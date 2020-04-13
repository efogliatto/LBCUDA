#include <energyGradient.h>

#include <stdlib.h>

#include <stdio.h>


void energyGradient( basicMesh* mesh, scalar* gradient, scalar* field, scalar* variable, int node_i, scalar cs_2, scalar delta_t) {

    for( uint j = 0 ; j < 3 ; j++ ) {

	// Move over model velocities

	for(uint k = 0 ; k < mesh->Q ; k++) {

	    int idx_nb = mesh->nb[node_i][k];	// index of neighbour to analize

	    if ( idx_nb >= 0){
					
		gradient[j] += ( field[k] * variable[idx_nb] * (scalar)mesh->lattice.vel[k*3+j] ) ;	
	    }

	    else {
		gradient[j] += 0.0;     //No implementado en los bordes
	    }
				
	}
									
	gradient[j] = gradient[j] / ( cs_2 * delta_t);     //Ver si es que el denominador esta afuera de la sumatoria o no

	}

}
