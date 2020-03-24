#include <cudaEnergyTemp.h>

#include <stdio.h>

extern "C" __global__ void cudaEnergyTemp( cuscalar* T, cuscalar* field, cuscalar* gamma_0, cuscalar delta_t, unit np, int Q) {

    int id = threadIdx.x + blockIdx.x*blockDim.x;

    // Suma de todas las componentes
    
    if( id < np ) {

		T[id] = 0;	    

		uint j = 0;

		while( j < Q ) {

	    	T[id] += field[ id*Q + j ];

			j++;
		}

		T[id]+= delta_t * gamma_0[id]

    }
    

}
