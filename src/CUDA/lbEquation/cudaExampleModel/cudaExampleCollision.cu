#include <cudaExampleCollision.h>

#include <cuda_runtime.h>

#include <stdio.h>

#include <stdlib.h>



extern "C" __global__ void cudaExampleCollision(cudaBasicMesh* mesh, cuscalar* field, cuscalar* rho, cuscalar* U ) {

    int id = threadIdx.x + blockIdx.x*blockDim.x;

   
    if( id < mesh->nPoints ) {


	printf("%d %d\n", id, mesh->lattice.q);	
	

	// Distribuciones parciales
    
	cuscalar m[9];   // m:  Distribucion en espacio de momentos
    
	cuscalar m_eq[9];   // meq: Distribucion de equilibrio en espacio de momentos



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
	    m[k] = m[k]  -  1*( m[k] - m_eq[k] );
	    

	
	
	// Vuelta al espacio de fases. field = invM * m

	for( uint i = 0 ; i < mesh->Q ; i++ ) {

	    field[id*mesh->Q + i] = 0;

	    for( uint j = 0 ; j < mesh->Q ; j++ ) {

		field[id*mesh->Q + i] += mesh->lattice.invM[i*mesh->Q + j] * m[j];

	    }

	}
	

	

    }

}
