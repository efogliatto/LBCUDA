#include <threadedZerothMoment.h>

#include <cuda_runtime.h>

#include <stdio.h>

#include <stdlib.h>



extern "C" __global__ void threadedZerothMoment(cuscalar* field, cuscalar* zeroth, int np, int Q ) {

    int idx = threadIdx.x + blockIdx.x*blockDim.x;
  
    while( idx < np ) {

    	int j, k = idx*Q;

    	cuscalar sum = 0;

    	for( j = 0 ; j < Q ; j++ ) {

    	    sum += field[ k + j ];

    	}


    	zeroth[idx] = sum;


	// Increase thread index

	idx += blockDim.x * gridDim.x;	
	
    }

}
