#include <exampleCollision.h>

#include <stdlib.h>



void exampleCollision( basicMesh* mesh, exampleModelCoeffs* relax, scalar* field, scalar* rho, scalar* U) {


    
    // Distribuciones parciales
    
    scalar m[9];   // m:  Distribucion en espacio de momentos
    
    scalar m_eq[9];   // meq: Distribucion de equilibrio en espacio de momentos



    
    // Colision sobre todos los nodos
    
    for( uint id = 0 ; id < mesh->nPoints ; id++ ) {
	


	// Magnitud de la velocidad
	
	scalar umag = 0;
	
	for( uint k = 0 ; k < 3 ; k++ )	
	    umag += U[id*3 + k] * U[id*3 + k];


	
	// Distribucion de equilibrio en espacio de momentos
	
	m_eq[0] = rho[id];
	m_eq[1] = rho[id] * (-2 + 3*umag);
	m_eq[2] = rho[id] * (1 - 3*umag);
	m_eq[3] = rho[id] * U[id*3];
	m_eq[4] = rho[id] * (-U[id*3]);
	m_eq[5] = rho[id] * U[id*3+1];
	m_eq[6] = rho[id] * (-U[id*3+1]);
	m_eq[7] = rho[id] * (U[id*3]*U[id*3] - U[id*3+1]*U[id*3+1]);
	m_eq[8] = rho[id] * U[id*3] * U[id*3+1];


	
	// Distribucion en espacio de momentos. m = M*field[id]

	for( uint i = 0 ; i < mesh->Q ; i++ ) {

	    m[i] = 0;

	    for( uint j = 0 ; j < mesh->Q ; j++ ) {

		m[i] += mesh->lattice.M[i*mesh->Q + j] * field[ id*mesh->Q + j ];

	    }

	}


      

	
	// Collision in momentum space
	
	for( uint k = 0 ; k < mesh->Q ; k++ )
	    m[k] = m[k]  -  relax->Tau[k]*( m[k] - m_eq[k] );
	    

	
	
	// Vuelta al espacio de fases. field = invM * m

	for( uint i = 0 ; i < mesh->Q ; i++ ) {

	    field[id*mesh->Q + i] = 0;

	    for( uint j = 0 ; j < mesh->Q ; j++ ) {

		field[id*mesh->Q + i] += mesh->lattice.invM[i*mesh->Q + j] * m[j];

	    }

	}
	


	
    }



}
