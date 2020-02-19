#include <exampleDensity.h>

#include <stdio.h>

void exampleDensity(scalar* rho, scalar* field, basicMesh* mesh) {


    // Suma de todas las componentes
    
    for( uint i = 0 ; i < mesh->nPoints ; i++ ) {

	rho[i] = 0;	    

	for( uint j = 0 ; j < mesh->Q ; j++ ) {

	    rho[i] += field[ i*mesh->Q + j ];

	}


    }
    

}
