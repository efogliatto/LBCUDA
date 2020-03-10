#include <cudaMomentoCollision.h>

#include <cuda_runtime.h>

#include <stdio.h>

#include <stdlib.h>

#include <cudaFuerza.h>

#include <cudaMomentoFunciondist.h>

extern "C" __global__ void cudaMomentoCollision( cuscalar* field, cuscalar* rho, cuscalar* U, cuscalar* f, cuscalar* fint, cuscalar* T, cuscalar* Tau, cuscalar* M, cuscalar* invM, uint np, uint Q, cuscalar delta_t_cu, int a, int b, cuscalar c, cuscalar cs_2, cuscalar G, cuscalar sigma) {
    

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

		//uint indices_s = Q;
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


		cuscalar p_EOS = 0.0;
			
		cuscalar psi = 0.0;

		cudaFuerzaPresionEOS( &p_EOS, rho[id] , T[id], a, b); 

		cudaFuerzaPsi( &psi, p_EOS, rho[id], c, cs_2, G);

		cudaFuerzaS(s, auxF, auxFint, auxU, psi, sigma, Tau, delta_t_cu) ;

		// Collision in momentum space
		
		uint k = 0 ;	

		while ( k < Q ){

			m[k] = ( m[k]  -  Tau[k]*( m[k] - m_eq[k] ) ) + ( delta_t_cu * ( 1 - 0.5 * Tau[k] ) * s[k] );
			
			k++;	

		}

		
		// Vuelta al espacio de fases. field = invM * m

		i=0;

		while ( i < Q ) {

			field[id*Q + i] = 0;

			uint j = 0 ;

			while ( j < Q ) {

				cuscalar aux = invM[i*Q + j] * m[j];

				field[id*Q + i] = field[id*Q + i] + aux;
			
				if ( id == 0){			
					
					printf("\t invM:%lf \t\t m:%lf \t\t field:%lf \n ",aux,m[j],field[id*Q + i]);

				}		
				j++;		
				
			}
			printf("\n");
			i++;

		}
	
				/*// DEBUGER DE VARIABLES	

			
				if ( id == 5 ){			
					printf("\n \t ESTOY EN CUDA \n\n ");
		
					printf("\n \t Calculo de S \n ");
					
					for( uint i = 0 ; i < Q ; i++ ) {
						printf("\t %f \t ", s[i]);
					}
					
					printf("\n ");
				
					printf("\n \t Calculo de m \n ");
					
					for( uint i = 0 ; i < Q ; i++ ) {
							printf("\t %f \t ", m[i]);
						}
					
					printf("\n ");
		
					printf("\n \t Calculo de field \n ");
						
					for( uint i = 0 ; i < Q ; i++ ) {
							printf("\t %f \t ", field[id*Q + i]);
						}
					
					printf("\n ");

					printf("\n \t Inversa de M \n ");

					for( uint i = 0 ; i < Q ; i++ ) {
						for( uint j = 0 ; j < Q ; j++ ) {
							printf("\t %f \t ", invM[i*Q + j]);
						}
						printf("\n ");	
						}
				
					printf("\n ");
				}
		
				// FIN DE DEBUGGER*/


    }

}
