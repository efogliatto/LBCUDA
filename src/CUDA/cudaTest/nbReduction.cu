#include <nbReduction.h>

#include <cuda_runtime.h>

#include <stdio.h>

#include <stdlib.h>



extern "C" __global__ void nbReduction(cuscalar* field, cuscalar* sum, int* nb, uint np, uint Q ) {

    int idx = threadIdx.x + blockIdx.x*blockDim.x;
   
    if( idx < np ) {

    	uint j;

	cuscalar nodesum = 0;

    	for( j = 0 ; j < Q ; j++ ) {

	    cuscalar nbsum = 0;

	    int nbid = nb[idx*Q + j];
	    
	    if( nbid != -1 ) {

		for( uint l = 0 ; l < Q ; l++ ) {

		    nbsum += field[ nbid*Q + l  ];

		}

	    }

	    nodesum += nbsum;

    	}


    	sum[idx] = nodesum;
	
    }

}
