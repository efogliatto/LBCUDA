#include <thomasReduction.h>

#include <cuda_runtime.h>

#include <stdio.h>

#include <stdlib.h>


extern "C" __global__ void thomasReduction(cuscalar* field, cuscalar* sum, int* nb, int np, int Q ) {

    int idx = threadIdx.x + blockIdx.x*blockDim.x;
   
    if( idx < np ) {

    	uint j=0;

	cuscalar nodesum = 0;

    	while( j < Q ) {

	    cuscalar nbsum = 0;

	    int nbid = nb[idx*Q + j];

	    j++;
	    
	    if( nbid != -1 ) {

		uint l = 0 ;

		while(  l < Q ) {

		    nbsum += field[ nbid*Q + l  ];
		    
		    l++;
		}

	    }

	    nodesum += nbsum;

    	}


    	sum[idx] = nodesum;
	
    }

}

