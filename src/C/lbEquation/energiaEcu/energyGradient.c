#include <energyGradient.h>

#include <stdlib.h>

#include <stdio.h>


void energyGradient( basicMesh* mesh, scalar* gradient, scalar* field, scalar* variable, scalar cs_2, scalar delta_t) {

	for( uint j = 0 ; j < 3 ; j++ ) {

		for( uint i = 0 ; i < mesh->nPoints ; i++ ){

			// Move over model velocities

			for(uint k = 0 ; k < mesh->Q ; k++) {

				int idx_nb = mesh->nb[i][k];	// index of neighbour to analize

					if ( idx_nb >= 0){
					
						gradient[ i * 3 + j ] += ( field[i] * variable[idx_nb] * (scalar)mesh->lattice.vel[k*3+j] ) ;	
					}

					else {
						gradient[ i * 3 + j ] += 0.0;     //No implementado en los bordes
					}
				
				}
									
				gradient[ i * 3 + j ] = gradient[ i * 3 + j ] / ( cs_2 * delta_t);     //Ver si es que el denominador esta afuera de la sumatoria o no
		}
	}

}