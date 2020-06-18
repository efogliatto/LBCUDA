#include <cudaEnergySource.h>

#include <cudaFDOperations.h>

#include <stdlib.h>

#include <stdio.h>

extern "C" __global__ void cudaEnergySource( cuscalar* s,
					     cuscalar* rho,
					     cuscalar* T,
					     cuscalar* U,
					     cuscalar* Tau,
					     cuscalar alpha_1,
					     cuscalar alpha_2,
					     cuscalar cs_2,
					     cuscalar Cv,
					     cuscalar b,
					     uint np,
					     uint Q,
					     int* lvel,
					     int* nb ) {

    
    // Thread index
    
    int id = threadIdx.x + blockIdx.x*blockDim.x;


    if( id < np ) {



	// Cached scalar values

	cuscalar _rho = rho[id];

	cuscalar _T = T[id];
	
	
    
	// Thermal difusivity
    
	cuscalar chi = (1/Tau[3] - 0.5) * (4.0 + 3.0 * alpha_1  + 2.0 * alpha_2) / 6.0;
	


	// Scalar fields gradients

	cuscalar gradT[3]   = {0,0,0};

	cuscalar gradRho[3] = {0,0,0};
	
	cudaScalarGradient( gradT, T, nb, id, Q );

	cudaScalarGradient( gradRho, rho, nb, id, Q );


	
	cuscalar first = 0;
	uint j = 0;

	while( j < 3 ){
	    first += gradT[j] * gradRho[j];
		j++;
	}
	
	first = first * chi / _rho;

	
	
	// Velocity divergence term

	cuscalar dp_dT = _rho / (1 - _rho * b);

	cuscalar divU;
	cudaVectorDivergence( &divU, U, nb, id, Q );

	cuscalar second = divU * _T * ( 1.0   -   dp_dT / (_rho * Cv) );


	
	// Update source at node
	
	s[id] = first + second;
	

    }

}

