#include <cudaMomentoVelocity.h>

#include <cuda_runtime.h>

#include <stdio.h>

#include <stdlib.h>



extern "C" __global__ void cudaMomentoVelocity(cuscalar* field, cuscalar* rho, cuscalar* U, int* lvel, int np, int Q, cuscalar delta_t, cuscalar* F ) {

    int idx = threadIdx.x + blockIdx.x*blockDim.x;
    
   
    if( idx < np ) {


	// Velocidad local
	
	cuscalar lv[3] = {0,0,0};


	// Indice sobre componentes de velocidad
	
	uint j = 0 ;

	while ( j < 3 ) {

	    
	    // Indice sobre componentes de la funcion de distribucion
	    
	    uint k = 0 ;

	    while ( k < Q ) {

		lv[j] += lvel[3*k + j] * field[idx*Q + k];
		    
		k++;

	    }

	    lv[j] += 0.5 * delta_t * F[idx * 3 + j];

	    j++;

	    
	}


	// Divide por densidad
	
	j = 0;

	while ( j < 3 ) {

	    lv[j] = lv[j] / rho[idx];
	
	    j++;

	}


	
	// Copia al arreglo global
	
	j = 0;

	while ( j < 3 ) {
	
	    U[idx*Q + j] = lv[j];
	
	    j++;

	}


	
    }

}
