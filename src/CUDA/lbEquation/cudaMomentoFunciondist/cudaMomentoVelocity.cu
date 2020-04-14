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
	
	for( uint j = 0 ; j < 3 ; j++ ) {

	    
	    // Move over model velocities
	    
	    for(uint k = 0 ; k < Q ; k++)
		lv[j] += (cuscalar)lvel[k*3+j] * field[idx*Q+k];

	
	    lv[j] += 0.5 * Ft[ idx * 3 + j ];
	
	}


	
	// Add interaction force and divide by density
	
	for( uint j = 0 ; j < 3 ; j++ )
	    lv[j] = lv[j] / rho[idx];
	


	// Copy to global array
	for(uint j = 0 ; j < 3 ; j++)	
	    U[idx*3+j] = lv[j];
	
	

    }

}
