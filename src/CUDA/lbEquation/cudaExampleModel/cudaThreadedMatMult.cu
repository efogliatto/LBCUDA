#include <cudaThreadedMatMult.h>

#include <stdio.h>


extern "C" __global__ void cudaThreadedMatMult(cuscalar* mat, cuscalar* vec, uint id, uint Q) {

    extern __shared__ cuscalar m[];
    
    int thid = threadIdx.x;

    if(thid < Q) {	
    
	m[thid] = 0;

	for( uint j = 0 ; j < Q ; j++ ) {

	    m[thid] += mat[thid*Q + j] * vec[ id*Q + j ];

	}

    }

}
