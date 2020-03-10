#include <cudaFuerzaFuerzaint.h>

#include <cudaFuerzaPresionEOS.h>

#include <cudaFuerzaPsi.h>

#include <stdio.h>


extern "C" __global__ void cudaFuerzaFuerzaint(cuscalar* fint, cuscalar* rho, cuscalar* T, int np, int Q,  int* lvel,int* nb, cuscalar G, cuscalar c, cuscalar cs_2, int a, int b) {


    int idx = threadIdx.x + blockIdx.x*blockDim.x;

	// Valores de los pesos del modelo D2Q9

	//cuscalar weight[(const int) Q];
	cuscalar weight[9];

	weight[0] = 0.0 ;	
	weight[1] = (1.0/3.0);    
	weight[2] = (1.0/3.0);
	weight[3] = (1.0/3.0);
	weight[4] = (1.0/3.0);
	weight[5] = (1.0/12.0);
	weight[6] = (1.0/12.0);
	weight[7] = (1.0/12.0);
	weight[8] = (1.0/12.0);

	
    // Suma de todas las componentes
    
    if( idx < np ) {

		if ( idx == 0 ) {
	
			printf("\n Fint calculada con CUDA \n\n");

			printf(" i: %d\n",idx);
		}
		// Local force
		
		cuscalar lf[3] = {0,0,0};

		// Move over velocity components
		uint j = 0;

		while( j < 3 ) {
			if ( idx == 0 ) 						
				printf("\t j: %d\n",j);

			cuscalar p_EOS = 0.0;
			
			cuscalar psi = 0.0;

			// Move over model velocities
			
			uint k = 0;

			//printf("\t Q: %d\n",Q);

			while( k < Q ) {

				int idx_nb = nb[idx * Q + k];	// index of neighbour to analize

				if ( idx_nb >= 0){  	//se podra cambiar por un while ? en caso de que si, ver como cambiar el else 
					
					cudaFuerzaPresionEOS( &p_EOS, rho[idx_nb] , T[idx_nb], a, b); 

					cudaFuerzaPsi( &psi, p_EOS, rho[idx], c, cs_2, G);
					
					lf[j] += (cuscalar)lvel[k*3+j] * weight[k] * psi ;	
				}

				else {
					lf[j] += 0.0;
				}
				if ( idx == 0 ) 
					printf("\t\t K:%d \t idx_nb:%d \t rho:%f \t p_EOS:%f \t psi:%f \t lvel:%f \t weight:%f \t lf:%f   \n",k,idx_nb,rho[idx],p_EOS,psi,(cuscalar)lvel[k*3+j],weight[k],lf[j]);

				k++;
			}

			// Se necesita utilizar el psi del nodo --> i que es en el que me encuentro

			cudaFuerzaPresionEOS( &p_EOS, rho[idx] , T[idx], a, b); 

			cudaFuerzaPsi( &psi, p_EOS, rho[idx], c, cs_2, G);
		
			lf[j] = ( - G ) * lf[j]  * psi;     
			
			j++;

		}


		// Copy to global array
		
		j = 0;
		
		while( j < 3 ) {
			fint[idx*3+j] = lf[j];
		
		//	printf("%lf \t",fint[i*3+j]);
		
			j++;
	
		}

		//printf("\n");

	}
	

	//printf("\nESTOY AFUERA DE FINT ------------\n\n");

}








