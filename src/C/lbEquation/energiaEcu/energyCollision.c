#include <energyCollision.h>

#include <stdlib.h>

#include <stdio.h>



void energyCollision( basicMesh* mesh, scalar* field, scalar* gamma_0,  energyCoeffs* relax, scalar delta_t) {
    
    // Distribuciones parciales
    
    scalar n[9];   // n:  Distribucion en espacio de momentos
    
    scalar n_eq[9];   // neq: Distribucion de equilibrio en espacio de momentos

	scalar Q_34 = relax->Tau[3] *(relax->Tau[2]*0.5 -1); // Valor de la matriz de relajación Q

	scalar Q_56 = relax->Tau[5] *(relax->Tau[4]*0.5 -1); // Valor de la matriz de relajación Q
    
    // Colision sobre todos los nodos
    
    for( uint id = 0 ; id < mesh->nPoints ; id++ ) {
		
		// Distribucion de equilibrio en espacio de momentos
		
		n_eq[0] = T[id];
		n_eq[1] = T[id] * field[id*mesh->Q];
		n_eq[2] = T[id] * field[id*mesh->Q+1];
		n_eq[3] = T[id] * ux;
		n_eq[4] = T[id] * (-ux);
		n_eq[5] = T[id] * uy;
		n_eq[6] = T[id] * (-uy);
		n_eq[7] = 0;
		n_eq[8] = 0;
		
		// Distribucion en espacio de momentos. n = M*field[id]
											
		for( uint i = 0 ; i < mesh->Q ; i++ ) {

			n[i] = 0;

			for( uint j = 0 ; j < mesh->Q ; j++ ) { 

				n[i] += mesh->lattice.M[i*mesh->Q + j] * field[ id*mesh->Q + j ];

			}
		}

 			// Collision in momentum space//--------------------------------
		
		for( uint k = 0 ; k < mesh->Q ; k++ ){
			if ( k == 0){
				n[k] = ( n[k]  -  relax->Tau[k]*( n[k] - n_eq[k] ) ) + ( delta_t * ( 1 - 0.5 * relax->Tau[k] ) * gamma_0[id] );
			}


			if ( k == 2){
				n[k] = ( n[k]  -  (relax->Tau[k]*( n[k] - n_eq[k] ) + Q_34 *( n[3] - n_eq[3] ) ) );
			}
			
			if ( k == 4){
				n[k] = ( n[k]  -  (relax->Tau[k]*( n[k] - n_eq[k] ) + Q_56 *( n[5] - n_eq[5] ) ) );
			}

			else{
				n[k] = ( n[k]  -  relax->Tau[k]*( n[k] - n_eq[k] ) );
			}
						
			
		}
			//-------------------------------------------------
		
		// Vuelta al espacio de fases. field = invM * n

		for( uint i = 0 ; i < mesh->Q ; i++ ) {

			field[id*mesh->Q + i] = 0;

			for( uint j = 0 ; j < mesh->Q ; j++ ) {

				scalar aux = mesh->lattice.invM[i*mesh->Q + j] * m[j];

				field[id*mesh->Q + i] = field[id*mesh->Q + i] + aux;
				
			}
			
		}
		
    }
	
}
