#include <cudaMomentoVelocity.h>

#include <cuda_runtime.h>

#include <stdio.h>

#include <stdlib.h>



extern "C" __global__ void cudaMomentoVelocity(cuscalar* field, cuscalar* rho, cuscalar* U, cuscalar* Ft, int* lvel, int np, int Q ) {

    int idx = threadIdx.x + blockIdx.x*blockDim.x;
  
   
    if( idx < np ) {

	
	// Velocidad local
	
	cuscalar lv[3] = {0,0,0};


	// Move over velocity components
	
	uint j = 0;

	while( j < 3 ) {

	    
	    // Move over model velocities
	    uint k =0;
	    while( k < Q ){
		lv[j] += (cuscalar)lvel[k*3+j] * field[idx*Q+k];
			k++;
		}
	
	    lv[j] += 0.5 * Ft[ idx * 3 + j ];
		
		j++;
	}


	
	// Add interaction force and divide by density
	
	j=0;

	while( j < 3 ){
	    lv[j] = lv[j] / rho[idx];
		j++;
	}


	// Copy to global array
	j=0;
	while( j < 3 )	{
	    U[idx*3+j] = lv[j];
		j++;
	}
	

    }

}
