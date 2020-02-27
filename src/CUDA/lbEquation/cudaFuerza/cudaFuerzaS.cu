#include <cudaFuerzaS.h>

#include <stdio.h>

#include <math.h>

extern "C" __global__ void cudaFuerzaS(scalar* S, scalar* f, scalar* fint, scalar* U, scalar* psi, scalar sigma, scalar tau_e, scalar tau_chi, basicMesh* mesh, scalar delta_t) {

    int idx = threadIdx.x + blockIdx.x*blockDim.x;

	// Valores de los pesos del modelo D2Q9


    if( idx < mesh->nPoints ) {



	scalar fintmag = 0.0;
	scalar dot = 0.0;

	uint k = 0 ;

	while( k < 3 )	{

	    fintmag += fint[idx*3 + k] * fint[idx*3 + k];

	    dot += U[idx*3 + k] * f[idx*3 + k];
	
	    k++;

	}

	scalar aux = 12 * sigma * fabsf( fintmag ) / ( psi[idx] * psi[idx] * delta_t );

	S[idx * mesh->Q + 0] = 0.0 ;	
	S[idx * mesh->Q + 1] = 6 * dot + ( aux / (tau_e - 0.5) )  ;    
	S[idx * mesh->Q + 2] = - 6 * dot - ( aux / (tau_chi - 0.5) )  ;
	S[idx * mesh->Q + 3] = f[0];
	S[idx * mesh->Q + 4] = - f[0];
	S[idx * mesh->Q + 5] = f[1];
	S[idx * mesh->Q + 6] = - f[1];
	S[idx * mesh->Q + 7] = 2 * ( U[0] * f[0] + U[1] * f[1] );
	S[idx * mesh->Q + 8] = ( U[0] * f[1] + U[1] * f[0] );

    }

}
