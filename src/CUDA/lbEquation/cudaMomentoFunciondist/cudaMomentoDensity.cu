#include <cudaMomentoDensity.h>

#include <cuda_runtime.h>

#include <stdio.h>

#include <stdlib.h>



extern "C" __global__ void cudaMomentoDensity(cuscalar* field, cuscalar* rho, int np, int Q ) {

    int idx = threadIdx.x + blockIdx.x*blockDim.x;
   
    if( idx < np ) {

    	int j= 0;

    	cuscalar sum = 0;

    	while ( j < Q ) {

    	    sum += field[ idx*Q + j ];
		
	    j++;	
	
    	}


    	rho[idx] = sum;
	
    }

}
