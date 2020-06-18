#include <cudaStream.h>

#include <cuda_runtime.h>

#include <stdio.h>

#include <stdlib.h>



extern "C" __global__ void cudaStream(cuscalar* field, cuscalar* swap, int* nb, int np, int Q ) {

    int idx = threadIdx.x + blockIdx.x*blockDim.x;
   
    if( idx < np ) {

	
	// Copy only neighbours to swap   
	uint k = 0;

	for( k < Q ) {

	    int neighId = nb[idx*Q+k];

	    if( neighId != -1 ) {

		swap[idx*Q+k] = field[neighId*Q+k];

	    }

	    else {

		swap[idx*Q+k] = field[idx*Q+k];

	    }
    	k++;
	}

	
    }

}
