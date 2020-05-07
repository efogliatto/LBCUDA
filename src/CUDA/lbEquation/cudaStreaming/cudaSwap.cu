#include <cudaSwap.h>

#include <cuda_runtime.h>

#include <stdio.h>

#include <stdlib.h>



extern "C" __global__ void cudaSwap(cuscalar* field, cuscalar* swap, int* nb, int np, int Q ) {

    int idx = threadIdx.x + blockIdx.x*blockDim.x;
   
    if( idx < np ) {

	for( uint k = 0 ; k < Q ; k++ ) {

	    field[idx*Q+k] = swap[idx*Q+k];
	    
	}
	
    }

}
