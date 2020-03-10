#include <momentoCollision.h>

#include <fuerzaS.h>

#include <fuerzaPsi.h>

#include <fuerzaPresionEOS.h>

#include <stdlib.h>

#include <stdio.h>



void momentoCollision( basicMesh* mesh, momentoModelCoeffs* relax, scalar* field, scalar* rho, scalar* U, scalar* f, scalar* fint, scalar* T, scalar delta_t, int a, int b, scalar c, scalar cs_2, scalar G, scalar sigma) {


    
    // Distribuciones parciales
    
    scalar m[9];   // m:  Distribucion en espacio de momentos
    
    scalar m_eq[9];   // meq: Distribucion de equilibrio en espacio de momentos

    
    // Colision sobre todos los nodos
    
    for( uint id = 0 ; id < mesh->nPoints ; id++ ) {
		
		//if ( id == 0 ) 			
		//	printf("\t i: %d\n",i);
		
		scalar S[9]={0,0,0,0,0,0,0,0,0};

		scalar auxU[3] = {0,0,0};
		scalar auxF[3] = {0,0,0};
		scalar auxFint[3] = {0,0,0};


		// Magnitud de la velocidad y copia de parametros auxiliares para el calculo de S
		

		scalar ux = U[id*3], uy = U[id*3 + 1], uz = U[id*3 + 2];

		scalar umag = ux*ux + uy*uy + uz*uz;

	//	printf( "\n ");	

		for( uint k = 0 ; k < 3 ; k++ )	{
						
			auxU[k] = U[id*3 + k];
			auxF[k] = f[id*3 + k];
			auxFint[k] = fint[id*3 + k];
	
	//   	    printf( "%f \t", auxFint[k] );

		}

	//	printf( "\n ");

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




		
		// Distribucion en espacio de momentos. m = M*field[id]
											
		for( uint i = 0 ; i < mesh->Q ; i++ ) {

			m[i] = 0;

			for( uint j = 0 ; j < mesh->Q ; j++ ) { 

				m[i] += mesh->lattice.M[i*mesh->Q + j] * field[ id*mesh->Q + j ];

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
			
			//if ( id == 0 ) 			
			//	printf("\t k:%d \t m:%lf\n",k,m[k]);
		
		}
		
		
		// Vuelta al espacio de fases. field = invM * m

		for( uint i = 0 ; i < mesh->Q ; i++ ) {

			field[id*mesh->Q + i] = 0;

			for( uint j = 0 ; j < mesh->Q ; j++ ) {

				field[id*mesh->Q + i] = field[id*mesh->Q + i] + mesh->lattice.invM[i*mesh->Q + j] * m[j];

				if ( id == 0 ){			
					printf("\t invM:%lf \t\t m:%lf \t\t field:%lf \n ",mesh->lattice.invM[i*mesh->Q + j],m[j],field[id*mesh->Q + i]);
				}

			}
			printf("\n");

		}
	
		//if ( id == 0 ) 			
		//		printf("\t field:%lf \n",m[k]);


		/*// DEBUGER DE VARIABLES	
			
			if ( id == 5 ){			
				printf("\n \t ESTOY EN C \n\n ");

				printf("\n \t Calculo de S \n ");
				
				for( uint i = 0 ; i < mesh->Q ; i++ ) {
					printf("\t %f \t ", S[i]);
				}
				
				printf("\n ");
			
				printf("\n \t Calculo de m \n ");
				
				for( uint i = 0 ; i < mesh->Q ; i++ ) {
						printf("\t %f \t ", m[i]);
					}
				
				printf("\n ");

				printf("\n \t Calculo de field \n ");
				
				for( uint i = 0 ; i < mesh->Q ; i++ ) {
						printf("\t %f \t ", field[id*mesh->Q + i]);
					}
				
				printf("\n ");

				printf("\n \t Inversa de M \n ");

					for( uint i = 0 ; i < mesh->Q ; i++ ) {
						for( uint j = 0 ; j < mesh->Q ; j++ ) {
							printf("\t %f \t ", mesh->lattice.invM[i*mesh->Q + j]);
						}
						printf("\n ");	
						}
				
					printf("\n ");




			}

		// FIN DE DEBUGGER*/



	
    }



}
