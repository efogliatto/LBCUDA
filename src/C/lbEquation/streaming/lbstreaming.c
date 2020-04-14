#include <lbstreaming.h>

void lbstreaming( scalar* field, scalar* swap, basicMesh* mesh) {


    // Propiedades de grilla

    uint q = mesh->Q;

    uint np = mesh->nPoints;

    
    // Copy only neighbours to swap   

    for( uint i = 0 ; i < np ; i++ ) {

    	for( uint k = 0 ; k < q ; k++ ) {

    	    int neighId = mesh->nb[i][k];

    	    if( neighId != -1 ) {

    		swap[i*q+k] = field[neighId*q+k];

    	    }

	    else {

		swap[i*q+k] = field[i*q+k];

	    }
    
    	}

    }



    // Copy back from swap
    
    for( uint i = 0 ; i < np ; i++ ) {

    	for( uint k = 0 ; k < q ; k++ ) {

    	    field[i*q+k] = swap[i*q+k];
	    
    	}

    }


}
