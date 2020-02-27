#include <fuerzaFuerzatotal.h>

#include <stdio.h>

void fuerzaFuerzatotal(scalar* f, scalar* fint, scalar* rho, scalar* g, basicMesh* mesh) {
	
    // Suma de todas las componentes

    for( uint i = 0 ; i < mesh->nPoints ; i++ ) {


	// Volumetric force add Interaccion force

	for(uint j = 0 ; j < 3 ; j++) {
	
	    f[i*3+j] = rho[i] * g[j] + fint[i*3+j];
	
	}

    }

}
