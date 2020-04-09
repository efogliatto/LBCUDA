#include <energyGradientU.h>

#include <stdlib.h>

#include <stdio.h>


void energyGradientU( basicMesh* mesh, scalar* gradient, scalar* field, scalar* velocity, int comp_vel, int node_i, scalar cs_2, scalar delta_t) {

	for( uint j = 0 ; j < 3 ; j++ ) {

		// Move over model velocities

		for(uint k = 0 ; k < mesh->Q ; k++) {

			int idx_nb = mesh->nb[node_i][k];	// index of neighbour to analize

			if ( idx_nb >= 0){
					
				gradient[j] += ( field[k] * velocity[idx_nb*3+comp_vel] * (scalar)mesh->lattice.vel[k*3+j] ) ;	
			}

			else {
				gradient[j] += 0.0;     //No implementado en los bordes
			}
				
		}
									
		gradient[j] = gradient[j] / ( cs_2 * delta_t);     //Ver si es que el denominador esta afuera de la sumatoria o no

	}

}