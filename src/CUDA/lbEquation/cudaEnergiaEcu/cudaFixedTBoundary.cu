#include <cudaFixedTBoundary.h>

#include <cudaEnergyEqDistNode.h>

#include <stdio.h>

extern "C" __global__ void cudaFixedTBoundary( cuscalar* field,
					       cuscalar* T,
					       cuscalar* U,
					       int* bdPoints,
					       int* nb,
					       cuscalar* invM,
					       cuscalar alpha_1,
					       cuscalar alpha_2,
					       cuscalar bdval,
					       uint bid,
                                               uint nbd,
					       uint maxNbd,
					       uint Q ) {

    
    // Thread index
    
    int idx = threadIdx.x + blockIdx.x*blockDim.x;


    // Calcular solo si el nodo pertenece a esta frontera
    
    if( ( idx >= (bid * maxNbd) )  &&  ( idx < (bid * maxNbd  + maxNbd) )  ) {



	// Lattice constants
    
	cuscalar f_eq_bnd[9];



	// Indice de nodo sobre frontera
	
	int id = bdPoints[idx];

	if( id != -1 ) {

		uint k;

	    // Distribucion de equilibrio sobre la frontera

	    cudaEnergyEqDistNode( f_eq_bnd, T, U, id, Q, invM, alpha_1, alpha_2 );	    
	


		// Update unknowk distributions
		
		k = 1;

	    while( k < Q ) {
			
	        if( nb[id*Q+k] == -1 ) {

		    field[id*Q+k] = f_eq_bnd[k];

	        }

			k++;
	    }





	    // Correction constants

	    scalar beta=0, kn=0, unk=0;
		
		k = 0;

	    while( k < Q ) {
			
	        if( nb[id*Q+k] == -1 ) {

		    unk += field[id*Q+k];

	        }

	        else {

		    kn += field[id*Q+k];
		
	        }
			k++;
	    }


	    beta = (bdval - kn) / unk;
		
		k = 0;

	    while( k < Q ) {
			
	        if( nb[id*Q+k] == -1 ) {

		    field[id*Q+k] = beta * field[id*Q+k];

	        }
			k++;
	    }

	    

	}







	

    }
    

}
