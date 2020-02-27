#include <cudaFuerzaFuerzaint.h>

#include <cudaFuerzaPsi.h>

#include <stdio.h>


extern "C" __global__ void cudaFuerzaFuerzaint(scalar* fint, scalar* psi, basicMesh* mesh, scalar G) {


       int idx = threadIdx.x + blockIdx.x*blockDim.x;

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
    
    if(  idx < mesh->nPoints ) {


	// Local force
	
	scalar lf[3] = {0,0,0};


	// Move over velocity components
	
	uint j = 0 ;

	while( j < 3 ) {

	    // Move over model velocities

	    uint k = 0 ;

	    while( k < mesh->Q ) {

		lf[j] += (scalar)mesh->lattice.vel[k*3+j] * weight[k] * psi[ mesh->nb[idx][k] ];
		
		k++;
    
	    }
	
	    lf[j] = ( - G ) * lf[j]  * psi[idx];     
	    
            j++;

	}


	// Copy to global array
	
	j =0;

	while( j < 3 ) {
	
	    fint[idx*3+j] = lf[j];

	    j++;
	
	}

    }

}
