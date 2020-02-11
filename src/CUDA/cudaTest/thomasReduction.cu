#include <thomasReduction.h>

#include <cuda_runtime.h>

#include <stdio.h>

#include <stdlib.h>


extern "C" __global__ void thomasReduction(cuscalar* field, cuscalar* sum, int* nb, int np, int Q ) {

    int idx = threadIdx.x + blockIdx.x*blockDim.x;
 
    int idy = threadIdx.y + blockIdx.y*blockDim.y;
  
    int idz = threadIdx.z + blockIdx.z*blockDim.z;

    if( idx < np ) {



	cuscalar nodesum = 0;

    	if ( idy < Q  ) {

	    cuscalar nbsum = 0;

	    int nbid = nb[idx*Q + idy];


	    
	    if( nbid != -1 ) {
		

		if( idz < Q ) {

		    nbsum += field[ nbid*Q + idz  ];
 

		}

	    }

	    nodesum += nbsum;

    	}


    	sum[idx] = nodesum;
	
    }

}

