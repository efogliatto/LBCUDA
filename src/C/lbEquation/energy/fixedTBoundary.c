#include <fixedTBoundary.h>

#include <energyEqDistNode.h>

#include <stdio.h>

#include <stdlib.h>

#include <string.h>

void fixedTBoundary( basicMesh* mesh, scalar* field, scalar* T, scalar* U, char* bdname, scalar bdval, scalar alpha_1, scalar alpha_2 ) {


    // Determinacion del indice de frontera
    
    uint bid = 0;
    
    for( uint i = 0 ; i < mesh->bd.nbd ; i++ ) {

	if( strcmp(mesh->bd.bdNames[i], bdname) == 0 )
	    bid = i;

    }




    // Lattice constants
    
    uint Q = mesh->Q;

    scalar f_eq_bnd[9];





    // Calculo sobre los elementos de esa frontera

    for( uint i = 0 ; i < mesh->bd.nbdelem[bid] ; i++ ) {


	// Indice de nodo sobre frontera
	
	uint id = mesh->bd.bdPoints[bid][i];



	// Distribucion de equilibrio sobre la frontera

	energyEqDistNode( f_eq_bnd, mesh, T, U, id, alpha_1, alpha_2 );
	


    	// Update unknowk distributions

    	for( uint k = 1 ; k < Q ; k++ ) {
			
    	    if( mesh->nb[id][k] == -1 ) {

    		field[id*Q+k] = f_eq_bnd[k];

    	    }

    	}





    	// Correction constants

    	scalar beta=0, kn=0, unk=0;

    	for( uint k = 0 ; k < Q ; k++ ) {
			
    	    if( mesh->nb[id][k] == -1 ) {

    		unk += field[id*Q+k];

    	    }

    	    else {

    		kn += field[id*Q+k];

    	    }

    	}


    	beta = (bdval - kn) / unk;

    	for( uint k = 0 ; k < Q ; k++ ) {
			
    	    if( mesh->nb[id][k] == -1 ) {

    		field[id*Q+k] = beta * field[id*Q+k];

    	    }

    	}	
	

	

    }


        

}
