#include <energyCollision.h>

#include <stdlib.h>

#include <stdio.h>


void energyCollision( basicMesh* mesh, scalar* field, scalar* gamma_0, scalar* T, scalar* U, energyCoeffs* relax, scalar delta_t) {

    
    
    // Distribuciones parciales
    
    scalar n[9];   //n:  Distribucion en espacio de momentos
    
    scalar n_eq[9];   // neq: Distribucion de equilibrio en espacio de momentos

    scalar aux[9];

    scalar Q_34 = relax->Tau[4] *(relax->Tau[3]*0.5 -1);

    scalar Q_56 = relax->Tau[6] *(relax->Tau[5]*0.5 -1);

    
    
    // Colision sobre todos los nodos
    
    for( uint id = 0 ; id < mesh->nPoints ; id++ ) {

	scalar ux = U[id*3], uy = U[id*3 + 1];

	scalar T_ = T[id];
	
		
	// Distribucion de equilibrio en espacio de momentos

	n_eq[0] = T_;
    	n_eq[1] = relax->alpha_1 * T_;       
    	n_eq[2] = relax->alpha_2 * T_;	
    	n_eq[3] = T_ * ux;	
    	n_eq[4] = T_ * (-ux);	
    	n_eq[5] = T_ * uy;	
    	n_eq[6] = T_ * (-uy);	
    	n_eq[7] = 0;	
    	n_eq[8] = 0;

	
		
	// Distribucion en espacio de momentos. n = M*field[id]
											
	for( uint i = 0 ; i < mesh->Q ; i++ ) {

	    n[i] = 0;

	    for( uint j = 0 ; j < mesh->Q ; j++ ) { 

		n[i] += mesh->lattice.M[i*mesh->Q + j] * field[ id*mesh->Q + j ];

	    }
	}



    	// Distribucion auxiliar: diag(Q) * ( n - n_eq )

    	for( uint k = 0 ; k < mesh->Q ; k++ )
    	    aux[k] = relax->Tau[k] * ( n[k] - n_eq[k] );


	// Correccion

	aux[3] = aux[3] + Q_34*( n[4] - n_eq[4] );

	aux[5] = aux[5] + Q_56*( n[6] - n_eq[6] );



        // Second auxiliary distribution: (I  -  0.5 * Q) * GammaHat	

    	scalar heat = (1.0 - 0.5 * relax->Tau[0])  * gamma_0[id];


	
	// Completa la colision
	
    	for( uint k = 0 ; k < mesh->Q ; k++ )
    	    n[k] = n[k] - aux[k];

	
    	n[0] += heat;






	
	//-------------------------------------------------
		
	// Vuelta al espacio de fases. field = invM * n

	for( uint i = 0 ; i < mesh->Q ; i++ ) {

	    field[id*mesh->Q + i] = 0;

	    for( uint j = 0 ; j < mesh->Q ; j++ ) {

		field[id*mesh->Q + i] = field[id*mesh->Q + i] + mesh->lattice.invM[i*mesh->Q + j] * n[j];
				
	    }
			
	}
		
    }
	
}
