#include <fuerzaFuerzaint.h>

#include <fuerzaPsi.h>

#include <stdio.h>

void fuerzaFuerzaint(scalar* fint, scalar* psi, basicMesh* mesh, scalar G) {

	// Valores de los pesos del modelo D2Q9

	scalar weight[9];

	weight[0] = 0.0 ;	
	weight[1] = (1/3);    
	weight[2] = (1/3);
	weight[3] = (1/3);
	weight[4] = (1/3);
	weight[5] = (1/12);
	weight[6] = (1/12);
	weight[7] = (1/12);
	weight[8] = (1/12);

	
    // Suma de todas las componentes
    
    for( uint i = 0 ; i < mesh->nPoints ; i++ ) {


	// Local force
	
	scalar lf[3] = {0,0,0};


	// Move over velocity components
	
	for( uint j = 0 ; j < 3 ; j++ ) {

	    // Move over model velocities
	    for(uint k = 0 ; k < mesh->Q ; k++) {

		lf[j] += (scalar)mesh->lattice.vel[k*3+j] * weight[k] * psi[mesh->nb[i * mesh->Q +k]];
		    
	    }
	
	    lf[j] = ( - G ) * lf[j]  * psi[i];     
	
	}


	// Copy to global array
	for(uint j = 0 ; j < 3 ; j++) {
	
	    fint[i*3+j] = lf[j];
	
	}

    }

}
