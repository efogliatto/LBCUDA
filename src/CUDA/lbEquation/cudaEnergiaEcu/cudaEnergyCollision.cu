#include <cudaEnergyCollision.h>

#include <stdlib.h>

#include <stdio.h>



extern "C" __global__ void cudaEnergyCollision( cuscalar* field,
						cuscalar* U,
						cuscalar* T,
						cuscalar* gamma_0,
                                                cuscalar* Tau,
						cuscalar  alpha_1,
						cuscalar  alpha_2,
						uint Q,
						uint np,
						cuscalar* M,
						cuscalar* invM ) {


    // Thread index
    
    int id = threadIdx.x + blockIdx.x*blockDim.x;



	if( id < np ) {
	
	
		// Distribuciones parciales
		
		cuscalar n[9];   //n:  Distribucion en espacio de momentos
		
		cuscalar n_eq[9];   // neq: Distribucion de equilibrio en espacio de momentos

		cuscalar aux[9];

		cuscalar Q_34 = Tau[4] *(Tau[3]*0.5 -1);

		cuscalar Q_56 = Tau[6] *(Tau[5]*0.5 -1);



	

		scalar ux = U[id*3], uy = U[id*3 + 1];

		scalar T_ = T[id];
		
		
		// Distribucion de equilibrio en espacio de momentos

		n_eq[0] = T_;
		n_eq[1] = alpha_1 * T_;       
		n_eq[2] = alpha_2 * T_;	
		n_eq[3] = T_ * ux;	
		n_eq[4] = T_ * (-ux);	
		n_eq[5] = T_ * uy;	
		n_eq[6] = T_ * (-uy);	
		n_eq[7] = 0;	
		n_eq[8] = 0;

	
		
		// Distribucion en espacio de momentos. n = M*field[id]
		
		uint i = 0;
		
		while( i < Q ) {

			n[i] = 0;

			uint j = 0;

			while( j < Q ) { 

				n[i] += M[i*Q + j] * field[ id*Q + j ];
			
				j++;
			}

			i++;
		}



		// Distribucion auxiliar: diag(Q) * ( n - n_eq )

		uint k = 0;

		while( k < Q ){
			
			aux[k] = Tau[k] * ( n[k] - n_eq[k] );
			
			k++;
		}

		// Correccion

		aux[3] = aux[3] + Q_34*( n[4] - n_eq[4] );

		aux[5] = aux[5] + Q_56*( n[6] - n_eq[6] );



		// Second auxiliary distribution: (I  -  0.5 * Q) * GammaHat	

		scalar heat = (1.0 - 0.5 * Tau[0])  * gamma_0[id];


	
		// Completa la colision

		k = 0;
	
		while( k < Q ){
			
			n[k] = n[k] - aux[k];
			
			k++;

		}
	
		n[0] += heat;






	
		//-------------------------------------------------
		
		// Vuelta al espacio de fases. field = invM * n

		i = 0;

		while( i < Q ) {

			field[id*Q + i] = 0;

			uint j = 0;

			while( j < Q ) {

				field[id*Q + i] = field[id*Q + i] + invM[i*Q + j] * n[j];
				
				j++;
			}
			
			i++;
		}



	}
	
}
