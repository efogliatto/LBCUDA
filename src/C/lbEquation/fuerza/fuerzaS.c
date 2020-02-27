#include <fuerzaS.h>

#include <stdio.h>

#include <math.h>

void fuerzaS(scalar* S, scalar* f, scalar* fint, scalar* U, scalar* psi, scalar sigma, scalar tau_e, scalar tau_chi, basicMesh* mesh, scalar delta_t) {

	// Valores de los pesos del modelo D2Q9


    for( uint i = 0 ; i < mesh->nPoints ; i++ ) {



	scalar fintmag = 0.0;
	scalar dot = 0.0;

	for( uint k = 0 ; k < 3 ; k++ )	{

	    fintmag += fint[i*3 + k] * fint[i*3 + k];

	    dot += U[i*3 + k] * f[i*3 + k];

	}

	scalar aux = 12 * sigma * fabsf( fintmag ) / ( psi[i] * psi[i] * delta_t );

	S[i * mesh->Q + 0] = 0.0 ;	
	S[i * mesh->Q + 1] = 6 * dot + ( aux / (tau_e - 0.5) )  ;    
	S[i * mesh->Q + 2] = - 6 * dot - ( aux / (tau_chi - 0.5) )  ;
	S[i * mesh->Q + 3] = f[0];
	S[i * mesh->Q + 4] = - f[0];
	S[i * mesh->Q + 5] = f[1];
	S[i * mesh->Q + 6] = - f[1];
	S[i * mesh->Q + 7] = 2 * ( U[0] * f[0] + U[1] * f[1] );
	S[i * mesh->Q + 8] = ( U[0] * f[1] + U[1] * f[0] );

    }

}
