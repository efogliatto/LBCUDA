#include <cudaMomentoCollision.h>

#include <cuda_runtime.h>

#include <stdio.h>

#include <stdlib.h>

#include <cudaThreadedMatMult.h>



extern "C" __global__ void cudaMomentoCollision( cuscalar* field, cuscalar* rho, cuscalar* U, cuscalar* Tau, cuscalar* M, cuscalar* invM, uint np, uint Q, cuscalar delta_t ) {
    

    int id = threadIdx.x + blockIdx.x*blockDim.x;

   
    if( id < np ) {


	// Distribuciones parciales
    
	cuscalar m[9];   // m:  Distribucion en espacio de momentos
    
	cuscalar m_eq[9];   // meq: Distribucion de equilibrio en espacio de momentos

	cuscalar s[9] = {0,0,0,0,0,0,0,0,0};	// s: Termino de fuente que se debe traer ya calculado 


	// Magnitud de la velocidad
	
	cuscalar ux = U[id*3], uy = U[id*3 + 1], uz = U[id*3 + 2];

	cuscalar umag = ux*ux + uy*uy + uz*uz;
	


	
	// Distribucion de equilibrio en espacio de momentos

	cuscalar localRho = rho[id];
	
	m_eq[0] = localRho;
	m_eq[1] = localRho * (-2 + 3*umag);
	m_eq[2] = localRho * (1 - 3*umag);
	m_eq[3] = localRho * ux;
	m_eq[4] = localRho * (-ux);
	m_eq[5] = localRho * uy;
	m_eq[6] = localRho * (-uy);
	m_eq[7] = localRho * (ux*ux - uy*uy);
	m_eq[8] = localRho * ux * uy;


	
	// Distribucion en espacio de momentos. m = M*field[id]

	uint i = 0 ;

	while ( i < Q ) {

	    m[i] = 0;
		
	    uint j = 0 ;		

	    while ( j < Q ) {

		m[i] += M[i*Q + j] * field[ id*Q + j ];

		j++;	

	    }
	
	    i++;	

	}

	
	/* cudaThreadedMatMult<<<1,9>>>(M, field, id, Q); */

	/* __syncthreads(); */
	

	
	// Collision in momentum space
	
	uint k = 0 ;	

	while ( k < Q ){

	    m[k] = ( m[k]  -  Tau[k]*( m[k] - m_eq[k] ) ) + ( delta_t * ( 1 - 0.5 * Tau[k] ) * s[k] );
	    
	    k++;	

	}
	
	// Vuelta al espacio de fases. field = invM * m

	i=0;
	uint j = 0 ;		

	while ( i < Q ) {

	    field[id*Q + i] = 0;

	    while ( j < Q ) {

		field[id*Q + i] += invM[i*Q + j] * m[j];
		
		j++;		

	    }

	    i++;

	}
	


    }

}
