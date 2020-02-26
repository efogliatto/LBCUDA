#include <fuerzaFuerzatotal.h>

#include <fuerzaFuerzaint.h>

#include <fuerzaPsi.h>

#include <fuerzaPresionEOS.h>

#include <stdio.h>

void fuerzaFuerzatotal(scalar* f, scalar* fint, scalar* rho, scalar* g, basicMesh* mesh, scalar* psi, scalar* T, scalar* p, scalar G, int a, int b, scalar c, scalar cs_2) {
	
    // Suma de todas las componentes

    fuerzaPresionEOS(p, rho, T, mesh, a, b);
    fuerzaPsi(psi, p, rho, c, cs_2, G, mesh);
    fuerzaFuerzaint(fint, psi, mesh, G);

    for( uint i = 0 ; i < mesh->nPoints ; i++ ) {


	// Volumetric force add Interaccion force

	for(uint j = 0 ; j < 3 ; j++) {
	
	    f[i*3+j] = rho[i] * g[j] + fint[i*3+j];
	
	}

    }

}
