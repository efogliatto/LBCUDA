#include <cudaEnergyTemp.h>

#include <stdio.h>

extern "C" __global__ void cudaEnergyTemp( cuscalar* T, cuscalar* field, cuscalar* gamma_0, uint np, uint Q) {

    int id = threadIdx.x + blockIdx.x*blockDim.x;

    
    // Suma de todas las componentes
    
    if( id < np ) {

	cuscalar acum = 0;	    
	uint j = 0 ;

	while( j < Q ) {

	    acum += field[ id*Q + j ];

		j++;
	}

	T[id] = acum + 0.5*gamma_0[id];	

    }
    

}
