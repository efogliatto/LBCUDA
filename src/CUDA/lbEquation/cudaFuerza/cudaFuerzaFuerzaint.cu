#include <cudaFuerzaFuerzaint.h>

#include <cudaFuerzaPresionEOS.h>

#include <cudaFuerzaPsi.h>

#include <stdio.h>


extern "C" __global__ void cudaFuerzaFuerzaint(cuscalar* fint, cuscalar* rho, cuscalar* T, int np, int Q,
					       int* lvel, int* reverse, int* nb, cuscalar G, cuscalar c, cuscalar cs_2, cuscalar a, cuscalar b) {


    int id = threadIdx.x + blockIdx.x*blockDim.x;

    
    if( id < np ) {

	
	// Valores de los pesos del modelo D2Q9

	scalar weight[9];

	weight[0] = 0.0 ;	
	weight[1] = (1.0/3.0);    
	weight[2] = (1.0/3.0);
	weight[3] = (1.0/3.0);
	weight[4] = (1.0/3.0);
	weight[5] = (1.0/12.0);
	weight[6] = (1.0/12.0);
	weight[7] = (1.0/12.0);
	weight[8] = (1.0/12.0);



	// Ver si el nodo tiene todos sus vecinos

	uint noNeigh = 0;

	for( uint k = 1 ; k < Q ; k++ ) {

	    if( nb[id*Q+k] == -1 )
		noNeigh = 1;

	}



	// Solo calcular fuerza en nodos que no estan sobre la pared

	cuscalar lf[3] = {0,0,0};
	
	if( noNeigh == 0 ) {

		uint k = 1;

	    while( k < Q ) {


	    	// Nodo vecino
       
	    	int neighId = nb[ id*Q + reverse[k] ];

	    	cuscalar _rho = rho[neighId];

	    	cuscalar _T = T[neighId];


	    	// Presion de estado en nodo vecino

	    	cuscalar p_EOS = 0;

	    	cudaFuerzaPresionEOS( &p_EOS, _rho , _T, a, b);

	    	cuscalar psi = 0;

	    	cudaFuerzaPsi( &psi, p_EOS, _rho, c, cs_2, G);

		

	    	// Suma para cada componente
	    
	    	cuscalar alpha = weight[k] * psi;

	    
	    	for( uint j = 0 ; j < 3 ; j++ )
	    	    lf[j] +=  alpha * (cuscalar)lvel[k*3+j] ;

			k++;
	    }



	    // Constante extra. Potencial en nodo

	    cuscalar p_EOS = 0;
	    
	    cudaFuerzaPresionEOS( &p_EOS, rho[id] , T[id], a, b);

	    cuscalar psi = 0;

	    cudaFuerzaPsi( &psi, p_EOS, rho[id], c, cs_2, G);
		


	    // Suma directamente en arreglo
		
		uint j = 0;
		
	    while( j < 3 )	{
			fint[id*3+j] =  lf[j] * (-G) * psi;
			j++;
		}
	    

	}

	
	// Sin fuerza sobre nodo de frontera
	
	else {

		uint j = 3;
	    while( j < 3 )	{
			fint[id*3+j] =  0;
			j++;
		}
	}	


    }
    
    



}










/* extern "C" __global__ void cudaFuerzaFuerzaint(cuscalar* fint, cuscalar* rho, cuscalar* T, int np, int Q, */
/* 					       int* lvel, int* nb, cuscalar G, cuscalar c, cuscalar cs_2, cuscalar a, cuscalar b) { */


/*     int idx = threadIdx.x + blockIdx.x*blockDim.x; */
    

/*     // Valores de los pesos del modelo D2Q9 */

/*     //cuscalar weight[(const int) Q]; */
/*     cuscalar weight[9]; */

/*     weight[0] = 0.0 ;	 */
/*     weight[1] = (1.0/3.0);     */
/*     weight[2] = (1.0/3.0); */
/*     weight[3] = (1.0/3.0); */
/*     weight[4] = (1.0/3.0); */
/*     weight[5] = (1.0/12.0); */
/*     weight[6] = (1.0/12.0); */
/*     weight[7] = (1.0/12.0); */
/*     weight[8] = (1.0/12.0); */

/*     // Vemos si la matriz de vecinos esta bien */

/*     if (idx == 5){ */
/* 	printf("\n\nvecinos en CUDA\n\n"); */
/* 	for(uint r = 0 ; r < np ; r++) { */
/* 	    for(uint y = 0 ; y < Q ; y++) { */
/* 		printf("\t %d",nb[r*Q+y]); */
/* 	    } */
/* 	    printf("\n"); */
/* 	} */
/*     } */
	
/*     // Suma de todas las componentes */
    
/*     if( idx < np ) { */

/* 	if ( idx == 0 ) { */
	
/* 	    printf("\n Fint calculada con CUDA \n\n"); */

/* 	    printf(" i: %d\n",idx); */
/* 	} */
/* 	// Local force */
		
/* 	cuscalar lf[3] = {0,0,0}; */

/* 	// Move over velocity components */
/* 	uint j = 0; */

/* 	while( j < 3 ) { */
/* 	    if ( idx == 0 ) 						 */
/* 		printf("\t j: %d\n",j); */

/* 	    cuscalar p_EOS = 0.0; */
			
/* 	    cuscalar psi = 0.0; */

/* 	    // Move over model velocities */
			
/* 	    uint k = 0; */

/* 	    //printf("\t Q: %d\n",Q); */

/* 	    while( k < Q ) { */

/* 		int idx_nb = nb[idx * Q + k];	// index of neighbour to analize */

/* 		if ( idx_nb >= 0){  	//se podra cambiar por un while ? en caso de que si, ver como cambiar el else  */
					
/* 		    cudaFuerzaPresionEOS( &p_EOS, rho[idx_nb] , T[idx_nb], a, b);  */

/* 		    cudaFuerzaPsi( &psi, p_EOS, rho[idx], c, cs_2, G); */
					
/* 		    lf[j] += (cuscalar)lvel[k*3+j] * weight[k] * psi ;	 */
/* 		} */

/* 		else { */
/* 		    lf[j] += 0.0; */
/* 		} */
/* 		if ( idx == 0 && j == 0 )  */
/* 		    printf("\t\t K:%d \t idx_nb:%d \t rho:%f \t p_EOS:%f \t psi:%f \t lvel:%f \t weight:%f \t lf:%f   \n",k,idx_nb,rho[idx],p_EOS,psi,(cuscalar)lvel[k*3+j],weight[k],lf[j]); */

/* 		k++; */
/* 	    } */

/* 	    // Se necesita utilizar el psi del nodo --> i que es en el que me encuentro */

/* 	    cudaFuerzaPresionEOS( &p_EOS, rho[idx] , T[idx], a, b);  */

/* 	    cudaFuerzaPsi( &psi, p_EOS, rho[idx], c, cs_2, G); */
		
/* 	    lf[j] = ( - G ) * lf[j]  * psi;      */
			
/* 	    j++; */

/* 	} */


/* 	// Copy to global array */
		
/* 	j = 0; */
		
/* 	while( j < 3 ) { */
/* 	    fint[idx*3+j] = lf[j]; */
		
/* 	    //	printf("%lf \t",fint[i*3+j]); */
		
/* 	    j++; */
	
/* 	} */

/* 	//printf("\n"); */

/*     } */
	



/* } */
