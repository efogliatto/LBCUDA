#include <energyEqDistMomento.h>

#include <stdlib.h>

#include <stdio.h>

void energyEqDistMomento( basicMesh* mesh, scalar* field, scalar* T, scalar* U, energyCoeffs* relax ) {

    
    // Distribuciones parciales
        
    scalar n_eq[9];   // neq: Distribucion de equilibrio en espacio de momentos

    
    // Campo en equilibrio de todos los nodos
    
    for( uint id = 0 ; id < mesh->nPoints ; id++ ) {
		

	// Magnitud de la velocidad 
		
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

	
	
	// Campo en equilibrio. field = invM * n_eq										       

	for( uint i = 0 ; i < mesh->Q ; i++ ) {

	    field[id*mesh->Q + i] = 0;

	    for( uint j = 0 ; j < mesh->Q ; j++ ) {

		scalar aux = mesh->lattice.invM[i*mesh->Q + j] * n_eq[j];

		field[id*mesh->Q + i] = field[id*mesh->Q + i] + aux;
				
	    }
			
	}

	
    }
    
	
}
