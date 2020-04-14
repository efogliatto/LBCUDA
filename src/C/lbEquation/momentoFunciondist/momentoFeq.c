#include <momentoFeq.h>

#include <stdlib.h>

#include <stdio.h>

void momentoFeq( basicMesh* mesh, scalar* field, scalar* rho, scalar* U) {

    // Distribuciones parciales
        
    scalar m_eq[9];   // meq: Distribucion de equilibrio en espacio de momentos

    
    // Campo en equilibrio de todos los nodos
    
    for( uint id = 0 ; id < mesh->nPoints ; id++ ) {
		

	// Magnitud de la velocidad 
		
	scalar ux = U[id*3], uy = U[id*3 + 1], uz = U[id*3 + 2];

	scalar umag = ux*ux + uy*uy + uz*uz;

	// Distribucion de equilibrio en espacio de momentos
		
	m_eq[0] = rho[id];
	m_eq[1] = rho[id] * (-2 + 3*umag);
	m_eq[2] = rho[id] * (1 - 3*umag);
	m_eq[3] = rho[id] * ux;
	m_eq[4] = rho[id] * (-ux);
	m_eq[5] = rho[id] * uy;
	m_eq[6] = rho[id] * (-uy);
	m_eq[7] = rho[id] * (ux*ux - uy*uy);
	m_eq[8] = rho[id] * ux * uy;

	
	// Campo en equilibrio. field = invM * m_eq										       

	for( uint i = 0 ; i < mesh->Q ; i++ ) {

	    field[id*mesh->Q + i] = 0;

	    for( uint j = 0 ; j < mesh->Q ; j++ ) {

		scalar aux = mesh->lattice.invM[i*mesh->Q + j] * m_eq[j];

		field[id*mesh->Q + i] = field[id*mesh->Q + i] + aux;
				
	    }
			
	}





	
    }

}        
