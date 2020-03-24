#include <cudaEnergyCollision.h>

#include <stdlib.h>

#include <stdio.h>



extern "C" __global__ void cudaEnergyCollision( cuscalar* field, cuscalar* gamma_0,  cudaEnergyCoeffs* relax, cuscalar delta_t, unit np, int Q, int* lvel,int* nb, cuscalar* Tau, cuscalar* M, cuscalar* invM) {
    
	int id = threadIdx.x + blockIdx.x*blockDim.x;

    // Distribuciones parciales
    
    cuscalar n[9];   // n:  Distribucion en espacio de momentos
    
    cuscalar n_eq[9];   // neq: Distribucion de equilibrio en espacio de momentos

	cuscalar Q_34 = Tau[3] *(Tau[2]*0.5 -1); // Valor de la matriz de relajación Q

	cuscalar Q_56 = Tau[5] *(Tau[4]*0.5 -1); // Valor de la matriz de relajación Q
    
    // Colision sobre todos los nodos
    
    if( id < np ) {
		
		uint i = 0;
		uint j = 0;
		uint k = 0;

		// Distribucion de equilibrio en espacio de momentos
		
		n_eq[0] = T[id];
		n_eq[1] = T[id] * field[id*Q];
		n_eq[2] = T[id] * field[id*Q+1];
		n_eq[3] = T[id] * ux;
		n_eq[4] = T[id] * (-ux);
		n_eq[5] = T[id] * uy;
		n_eq[6] = T[id] * (-uy);
		n_eq[7] = 0;
		n_eq[8] = 0;
		
		// Distribucion en espacio de momentos. n = M*field[id]
											
		while( i < Q ) {

			n[i] = 0;

			while( j < Q ) { 

				n[i] += M[i*Q + j] * field[ id*Q + j ];

				j++;
			}

			i++;
		}

 			// Collision in momentum space//--------------------------------
		
		while( k < Q ){
			if ( k == 0){
				n[k] = ( n[k]  -  Tau[k]*( n[k] - n_eq[k] ) ) + ( delta_t * ( 1 - 0.5 * Tau[k] ) * gamma_0[id] );
			}


			if ( k == 2){
				n[k] = ( n[k]  -  (Tau[k]*( n[k] - n_eq[k] ) + Q_34 *( n[3] - n_eq[3] ) ) );
			}
			
			if ( k == 4){
				n[k] = ( n[k]  -  (Tau[k]*( n[k] - n_eq[k] ) + Q_56 *( n[5] - n_eq[5] ) ) );
			}

			else{
				n[k] = ( n[k]  -  Tau[k]*( n[k] - n_eq[k] ) );
			}
						
			k++
		}
			//-------------------------------------------------
		
		// Vuelta al espacio de fases. field = invM * n

		i=0;
		j=0;

		while( i < Q ) {

			field[id*Q + i] = 0;

			while( j < Q ) {

				cuscalar aux = invM[i*Q + j] * m[j];

				field[id*Q + i] = field[id*Q + i] + aux;
				
				j++;
			}
			
			i++;
		}
		
    }
	
}
