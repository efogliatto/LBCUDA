#include <cudaFuerzaFuerzaint.h>

#include <cudaFuerzaPresionEOS.h>

#include <cudaFuerzaPsi.h>

#include <stdio.h>


extern "C" __global__ void cudaFuerzaFuerzaint(cuscalar* fint, cuscalar* rho, cuscalar* T, int np, int Q,  int* lvel,int* nb, cuscalar G, cuscalar c, cuscalar cs_2, int a, int b) {


    int idx = threadIdx.x + blockIdx.x*blockDim.x;

	// Valores de los pesos del modelo D2Q9

	//const int aux = (const int)Q;
	const int aux = 9;

	scalar weight[aux];

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
    
    if(  idx < np ) {

		// Local force
	
		scalar lf[3] = {0,0,0};


		// Move over velocity components
	
		uint j = 0 ;

		while( j < 3 ) {

	    // Move over model velocities

	    	uint k = 0 ;

			cuscalar p_EOS = 0.0;
			cuscalar psi = 0.0;

	    	while( k < Q ) {

				int idx_nb = nb[idx * Q + k];	// index of neighbour to analize

				if ( idx_nb >= 0){
					
					cudaFuerzaPresionEOS( &p_EOS, rho[idx_nb] , T[idx_nb], a, b); 

					cudaFuerzaPsi( &psi, p_EOS, rho[idx], c, cs_2, G);
	
					
					lf[j] += (cuscalar)lvel[k*3+j] * weight[k] * psi ;
				}

				else {
					lf[j] += 0.0;
				}
		
				k++;
    		}	
			
			cudaFuerzaPresionEOS( &p_EOS, rho[idx] , T[idx], a, b); 

			cudaFuerzaPsi( &psi, p_EOS, rho[idx], c, cs_2, G);
	
		    lf[j] = ( - G ) * lf[j]  * psi;     
	    
            j++;

		}


	// Copy to global array
	
		j =0;

		while( j < 3 ) {
	
	    	fint[idx*3+j] = lf[j];

	    	j++;
	
		}

    }
}
