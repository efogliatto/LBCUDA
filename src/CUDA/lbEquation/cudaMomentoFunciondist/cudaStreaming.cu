#include <cudaStreaming.h>

#include <cuda_runtime.h>

#include <stdio.h>

#include <stdlib.h>



extern "C" __global__ void cudaStreaming(cuscalar* field, cuscalar* swap, int* nb, int np, int Q ) {

    int idx = threadIdx.x + blockIdx.x*blockDim.x;
   
    if( idx < np ) {

	
	// Copy only neighbours to swap   

	for( uint i = 0 ; i < np ; i++ ) {

	    for( uint k = 0 ; k < Q ; k++ ) {

		int neighId = nb[i*Q+k];

		if( neighId != -1 ) {

		    swap[i*Q+k] = field[neighId*Q+k];

		}

		else {

		    swap[i*Q+k] = field[i*Q+k];

		}
    
	    }

	}



	// Copy back from swap
    
	for( uint i = 0 ; i < np ; i++ ) {

	    for( uint k = 0 ; k < Q ; k++ ) {

		field[i*Q+k] = swap[i*Q+k];
	    
	    }

	}
	
    }

}
