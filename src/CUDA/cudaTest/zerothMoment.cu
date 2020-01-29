#include <zerothMoment.h>

#include <cuda_runtime.h>

#include <stdio.h>

#include <stdlib.h>



__global__ void zerothMoment(cuscalar* field, cuscalar* zeroth, uint npoints, uint Q ) {

    int idx = threadIdx.x + blockIdx.x*blockDim.x;

    if( idx < npoints ) {

    	uint j;

    	cuscalar sum = 0;

    	for( j = 0 ; j < Q ; j++ ) {

    	    sum += field[ idx*Q + j ];

    	}


    	zeroth[idx] = sum;
	
    }

}
