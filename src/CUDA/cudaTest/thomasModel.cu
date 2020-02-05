#include <thomasModel.h>

#include <cuda_runtime.h>

#include <stdio.h>

#include <stdlib.h>



extern "C" __global__ void thomasModel(cuscalar* field, cuscalar* zeroth, int np, int Q ) {

    int idx = threadIdx.x + blockIdx.x * blockDim.x;

    int idy = threadIdx.y + blockIdx.y * blockDim.y;

    int idz = threadIdx.z + blockIdx.z * blockDim.z;

	
   // int j=0;	
   
    if( idx < np ) {
  	

    	cuscalar sum = 0;
	if( idy < Q ) {
    		if( idz < Q ) {

    	    	sum += field[ idx*Q + idz ];

		}

    	}


    	zeroth[idx] = sum;
	
    }

}
