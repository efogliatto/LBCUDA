#include <energyCollision.h>

#include <fuerzaS.h>

#include <fuerzaPsi.h>

#include <fuerzaPresionEOS.h>

#include <stdlib.h>

#include <stdio.h>



void energiaCollision( basicMesh* mesh, energyCoeffs* relax, scalar* field, scalar* rho, scalar* U, scalar* f, scalar* fint, scalar* T, scalar delta_t, int a, int b, scalar c, scalar cs_2, scalar G, scalar sigma) {


    
    // Distribuciones parciales
    
    scalar n[9];   // n:  Distribucion en espacio de momentos
    
    scalar n_eq[9];   // neq: Distribucion de equilibrio en espacio de momentos

    
    // Colision sobre todos los nodos
    
    for( uint id = 0 ; id < mesh->nPoints ; id++ ) {
		
		scalar S[9]={0,0,0,0,0,0,0,0,0};

		scalar auxU[3] = {0,0,0};
		scalar auxF[3] = {0,0,0};
		scalar auxFint[3] = {0,0,0};


		// Magnitud de la velocidad y copia de parametros auxiliares para el calculo de S
		

		scalar ux = U[id*3], uy = U[id*3 + 1], uz = U[id*3 + 2];

		for( uint k = 0 ; k < 3 ; k++ )	{
						
			auxU[k] = U[id*3 + k];
			auxF[k] = f[id*3 + k];
			auxFint[k] = fint[id*3 + k];
	
		}

		// Distribucion de equilibrio en espacio de momentos
		
		n_eq[0] = T[id];
		n_eq[1] = T[id] * field[id*mesh->Q];
		n_eq[2] = T[id] * field[id*mesh->Q+1];
		n_eq[3] = T[id] * ux;
		n_eq[4] = T[id] * (-ux);
		n_eq[5] = T[id] * uy;
		n_eq[6] = T[id] * (-uy);
		n_eq[7] = 0;
		n_eq[8] = 0;
		
		// Distribucion en espacio de momentos. n = M*field[id]
											
		for( uint i = 0 ; i < mesh->Q ; i++ ) {

			n[i] = 0;

			for( uint j = 0 ; j < mesh->Q ; j++ ) { 

				n[i] += mesh->lattice.M[i*mesh->Q + j] * field[ id*mesh->Q + j ];

			}

		}

		// Calulo de S termino de fuente

		scalar p_EOS = 0.0;
		
		scalar psi = 0.0;

		fuerzaPresionEOS( &p_EOS, rho[id] , T[id], a, b); 	

		fuerzaPsi( &psi, p_EOS, rho[id], c, cs_2, G);

		fuerzaS(S, auxF, auxFint, auxU, psi, sigma, relax->Tau, delta_t) ;

		// Collision in momentum space
		
		for( uint k = 0 ; k < mesh->Q ; k++ ){
		
			m[k] = ( m[k]  -  relax->Tau[k]*( m[k] - m_eq[k] ) ) + ( delta_t * ( 1 - 0.5 * relax->Tau[k] ) * S[k] );
			
		}
		
		
		// Vuelta al espacio de fases. field = invM * m

		for( uint i = 0 ; i < mesh->Q ; i++ ) {

			field[id*mesh->Q + i] = 0;

			for( uint j = 0 ; j < mesh->Q ; j++ ) {

				scalar aux = mesh->lattice.invM[i*mesh->Q + j] * m[j];

				field[id*mesh->Q + i] = field[id*mesh->Q + i] + aux;
				
			}
			
		}
		
    }
	
}
