#include <zerothMoment.h>

#include <cuda_runtime.h>

#include <stdio.h>

#include <stdlib.h>



extern "C" __global__ void zerothMoment(cuscalar* field, cuscalar* zeroth, int np, int Q ) {

    int idx = threadIdx.x + blockIdx.x*blockDim.x;
   
    if( idx < np ) {

    	int j;

    	cuscalar sum = 0;

    	for( j = 0 ; j < Q ; j++ ) {

    	    sum += field[ idx*Q + j ];

    	}


    	zeroth[idx] = sum;
	
    }

}
