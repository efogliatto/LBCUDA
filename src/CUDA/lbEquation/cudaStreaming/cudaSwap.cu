#include <cudaSwap.h>

#include <cuda_runtime.h>

#include <stdio.h>

#include <stdlib.h>



extern "C" __global__ void cudaSwap(cuscalar* field, cuscalar* swap, int* nb, int np, int Q ) {

    int idx = threadIdx.x + blockIdx.x*blockDim.x;
   
    if( idx < np ) {

        uint k = 0;

	while( k < Q ) {

	    field[idx*Q+k] = swap[idx*Q+k];
	    k++;
	}
	
    }

}
