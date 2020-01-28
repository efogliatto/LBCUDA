#include <zerothMoment.h>

#include <cuda_runtime.h>

#include <stdio.h>

#include <stdlib.h>



__host__ __device__ void zerothMoment(cuscalar* field, cuscalar* zeroth, basicMesh* mesh ) {

    int idx = threadIdx.x + blockIdx.x*blockDim.x;

    if( idx <  mesh.nPoints) {

	uint j;

	cuscalar sum = 0;

	for( j = 0 ; j < mesh.Q ; j++ ) {

	    sum += field[ idx*mesh.Q + j ];

	}


	zeroth[idx] = sum;

    }

}
