#include <zerothMomentCPU.h>

#include <stdio.h>

void zerothMomentCPU(scalar* sum, scalar* field, basicMesh* mesh) {


    // Suma de todas las componentes
    
    for( uint i = 0 ; i < mesh->nPoints ; i++ ) {

	sum[i] = 0;	    

	for( uint j = 0 ; j < mesh->Q ; j++ ) {

	    sum[i] += field[ i*mesh->Q + j ];

	}


    }
    

}
