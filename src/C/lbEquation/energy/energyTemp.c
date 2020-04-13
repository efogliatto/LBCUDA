#include <energyTemp.h>

#include <stdio.h>

void energyTemp( basicMesh* mesh, scalar* T, scalar* field, scalar* gamma_0, scalar delta_t ) {


    // Suma de todas las componentes
    
    for( uint i = 0 ; i < mesh->nPoints ; i++ ) {

	T[i] = 0;	    

	for( uint j = 0 ; j < mesh->Q ; j++ ) {

	    T[i] += field[ i*mesh->Q + j ];

	}

	T[i]+= delta_t * gamma_0[i];

    }
    
}
