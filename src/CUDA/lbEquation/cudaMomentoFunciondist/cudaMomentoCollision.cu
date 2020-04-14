#include <cudaMomentoCollision.h>

#include <cuda_runtime.h>

#include <stdio.h>

#include <stdlib.h>

#include <cudaFuerza.h>


extern "C" __global__ void cudaMomentoCollision( cuscalar* field, cuscalar* rho, cuscalar* U, cuscalar* f,
						 cuscalar* fint, cuscalar* T, cuscalar* Tau, cuscalar* M,
						 cuscalar* invM, uint np, uint Q, cuscalar delta_t_cu,
						 cuscalar a, cuscalar b, cuscalar c, cuscalar cs_2, cuscalar G, cuscalar sigma) {
    

    // Thread index
    
    int id = threadIdx.x + blockIdx.x*blockDim.x;

   
    if( id < np ) {


	// Distribuciones parciales
    
	cuscalar m[9];   // m:  Distribucion en espacio de momentos
    
	cuscalar m_eq[9];   // meq: Distribucion de equilibrio en espacio de momentos


	// Magnitud de la velocidad
		
	cuscalar ux = U[id*3], uy = U[id*3 + 1], uz = U[id*3 + 2];

	cuscalar umag = ux*ux + uy*uy + uz*uz;

	
	// Copia de parametros auxiliares para el calculo de S

	cuscalar auxU[3] = {0,0,0};
	cuscalar auxF[3] = {0,0,0};
	cuscalar auxFint[3] = {0,0,0};
	cuscalar s[9] = {0,0,0,0,0,0,0,0,0};


	for( uint k = 0 ; k < 3 ; k++ )	{
			
	    auxU[k] = U[id*3 + k];
	    auxF[k] = f[id*3 + k];
	    auxFint[k] = fint[id*3 + k];
		
	}

	for( uint k = 0 ; k < Q ; k++ )	{

	    s[k] = 0.0 ;

	}	

		
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

	for( uint i = 0 ; i < Q ; i++ ) {

	    m[i] = 0;

	    for( uint j = 0 ; j < Q ; j++ ) {

		m[i] += M[i*Q + j] * field[ id*Q + j ];

	    }

	}
	
	/* // Distribucion en espacio de momentos. m = M*field[id] */

	/* uint i = 0 ; */

	/* while ( i < Q ) { */

	/*     m[i] = 0; */
			
	/*     uint j = 0 ;		 */

	/*     while ( j < Q ) { */

	/* 	m[i] += M[i*Q + j] * field[ id*Q + j ]; */
				

	/* 	j++;	 */
	/*     } */
			

	/*     i++;	 */
	/* } */


	// Calculo de S termino de fuente
	
	cuscalar p_EOS = 0.0;
			
	cuscalar psi = 0.0;

	cudaFuerzaPresionEOS( &p_EOS, rho[id] , T[id], a, b); 

	cudaFuerzaPsi( &psi, p_EOS, rho[id], c, cs_2, G);

	cudaFuerzaS(s, auxF, auxFint, auxU, psi, sigma, Tau, delta_t_cu) ;



	
	// Collision in momentum space

	for( uint k = 0 ; k < Q ; k++ )
	    m[k] = ( m[k]  -  Tau[k]*( m[k] - m_eq[k] ) ) + ( ( 1 - 0.5 * Tau[k] ) * s[k] );
	
	
	/* uint k = 0 ;	 */

	/* while ( k < Q ){ */

	/*     m[k] = ( m[k]  -  Tau[k]*( m[k] - m_eq[k] ) ) + ( delta_t_cu * ( 1 - 0.5 * Tau[k] ) * s[k] ); */
			
	/*     k++;	 */
			
	/* } */


	
		
	// Vuelta al espacio de fases. field = invM * m

	for( uint i = 0 ; i < Q ; i++ ) {

	    field[id*Q + i] = 0;

	    for( uint j = 0 ; j < Q ; j++ ) {

		field[id*Q + i] += invM[i*Q + j] * m[j];

	    }

	}
	
	
	/* i=0; */
	/* while ( i < Q ) { */

	/*     field[id*Q + i] = 0; */

	/*     uint j = 0 ; */

	/*     while ( j < Q ) { */

	/* 	cuscalar aux = invM[i*Q + j] * m[j]; */

	/* 	field[id*Q + i] = field[id*Q + i] + aux; */
			
	/* 	j++;	 */
	
	/*     } */
	/*     i++;		 */
			

	/* } */

	
		
    }

}
