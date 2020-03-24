#include <cudaEnergyGradientU.h>

#include <stdlib.h>

#include <stdio.h>


extern "C" __device__ void cudaEnergyGradientU( cuscalar* gradient, cuscalar* field, cuscalar* velocity, int comp_vel, int node_i, cuscalar cs_2, cuscalar delta_t, int Q,  int* lvel,int* nb) {

	uint j = 0;

	uint k = 0;

	while( j < 3 ) {

		// Move over model velocities

		while( k < Q ) {

			int idx_nb = nb[node_i * Q + k];	// index of neighbour to analize

			if ( idx_nb >= 0){
					
				gradient[j] += ( field[k] * velocity[idx_nb*3+comp_vel] * (cuscalar)lvel[k*3+j] ) ;	
			}

			else {
				gradient[j] += 0.0;     //No implementado en los bordes
			}

			k++;	
		}
									
		gradient[j] = gradient[j] / ( cs_2 * delta_t);     //Ver si es que el denominador esta afuera de la sumatoria o no

		j++;
	}

}