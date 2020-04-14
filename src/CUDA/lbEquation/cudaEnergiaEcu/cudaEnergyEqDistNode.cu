#include <cudaEnergyEqDistNode.h>

extern "C" __device__ void cudaEnergyEqDistNode( cuscalar* eq,
						 cuscalar* T,
						 cuscalar* U,
						 uint id,
						 uint Q,
						 cuscalar* invM,
						 cuscalar alpha_1,
						 cuscalar alpha_2 ) {

    // Distribuciones parciales
        
    cuscalar n_eq[9];   // neq: Distribucion de equilibrio en espacio de momentos

   

    // Magnitud de la velocidad 
		
    cuscalar ux = U[id*3], uy = U[id*3 + 1];

    cuscalar T_ = T[id];


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

	
	
    // Campo en equilibrio. field = invM * n_eq										       

    for( uint i = 0 ; i < Q ; i++ ) {

	eq[i] = 0;

	for( uint j = 0 ; j < Q ; j++ ) {

	    scalar aux = invM[i*Q + j] * n_eq[j];

	    eq[i] = eq[i] + aux;
				
	}
			
    }

}
