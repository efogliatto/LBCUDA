#include <cudaExampleVelocity.h>

#include <cuda_runtime.h>

#include <stdio.h>

#include <stdlib.h>



extern "C" __global__ void cudaExampleVelocity(cuscalar* field, cuscalar* rho, cuscalar* U, int* lvel, int np, int Q ) {

    int idx = threadIdx.x + blockIdx.x*blockDim.x;
    printf("%d\n",idx);    
   
    if( idx < np ) {


	// Velocidad local
	
	cuscalar lv[3] = {0,0,0};



	// Indice sobre componentes de velocidad
	
	for( uint j = 0 ; j < 3 ; j++ ) {

	    
	    // Indice sobre componentes de la funcion de distribucion
	    
	    for( uint k = 0 ; k < Q ; k++ ) {

		lv[j] += lvel[3*k + j] * field[idx*Q + k];
		    
	    }
	    
	}


	// Divide por densidad
	
	for( uint j = 0 ; j < 3 ; j++ ) {

	    lv[j] = lv[j] / rho[idx];
	
	}


	
	// Copa al arreglo global
	
	for( uint j = 0 ; j < 3 ; j++ ) {
	
	    U[idx*Q + j] = lv[j];
	
	}


	
    }

}
