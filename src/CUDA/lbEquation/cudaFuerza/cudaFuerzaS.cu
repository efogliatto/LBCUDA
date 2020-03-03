#include <cudaFuerzaS.h>

#include <stdio.h>

#include <math.h>

__global__ void cudaFuerzaS(cuscalar* S, cuscalar* f, cuscalar* fint, cuscalar* U, cuscalar psi, cuscalar sigma, cuscalar* tau, scalar delta_t) {

	cuscalar fintmag = 0.0;
	cuscalar dot = 0.0;

	uint k = 0 ;

	while( k < 3 )	{

	    fintmag += fint[k] * fint[k];

	    dot += U[k] * f[k];
	
	    k++;

	}

	cuscalar aux = 12 * sigma * fabsf( fintmag ) / ( psi * psi * delta_t );

	S[0] = 0.0 ;	
	S[1] = 6 * dot + ( aux / (tau[1] - 0.5) )  ;    
	S[2] = - 6 * dot - ( aux / (tau[2] - 0.5) )  ;
	S[3] = f[0];
	S[4] = - f[0];
	S[5] = f[1];
	S[6] = - f[1];
	S[7] = 2 * ( U[0] * f[0] + U[1] * f[1] );
	S[8] = ( U[0] * f[1] + U[1] * f[0] );

}







