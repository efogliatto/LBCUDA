#include <fuerzaS.h>

#include <stdio.h>

#include <math.h>

void fuerzaS(scalar* S, scalar* f, scalar* fint, scalar* U, scalar psi, scalar sigma, scalar* tau, scalar delta_t) {

	scalar fintmag = 0.0;
	scalar dot = 0.0;

	for( uint k = 0 ; k < 3 ; k++ )	{

	    fintmag += fint[k] * fint[k];

	    dot += U[k] * f[k];

	}

	scalar aux = 12 * sigma * fabsf( fintmag ) / ( psi * psi * delta_t );

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
