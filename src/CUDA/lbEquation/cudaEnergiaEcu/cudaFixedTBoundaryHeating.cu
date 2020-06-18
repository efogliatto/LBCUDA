#include <cudaFixedTBoundaryHeating.h>

#include <cudaEnergyEqDistNode.h>

#include <stdio.h>

extern "C" __global__ void cudaFixedTBoundaryHeating( cuscalar* field,
						      cuscalar* T,
						      cuscalar* U,
						      int* bdPoints,
						      int* nb,
						      cuscalar* invM,
						      cuscalar alpha_1,
						      cuscalar alpha_2,
						      cuscalar bdval,
						      cuscalar bdheat,
						      uint widthbd,
						      uint bid,
						      uint nbd,
						      uint maxNbd,
						      uint Q ) {

    
    // Thread index
	
        
    int idx = threadIdx.x + blockIdx.x*blockDim.x;
	
	uint i = (bid * maxNbd);
	uint aux = 0;

	while( i < (bid * maxNbd  + maxNbd)){
		
		if(bdPoints[i]==-1){

			aux = i;
			
			i=(bid * maxNbd  + maxNbd);
		}

		i++;
	}

	
    uint since = (((maxNbd*bid)+aux)/2.0) + 1 - (widthbd/2.0);
    uint until = since + widthbd ;



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

			while( k < Q ) {
			
				if( nb[id*Q+k] == -1 ) {
	
				unk += field[id*Q+k];
	
				}
	
				else {
	
				kn += field[id*Q+k];
			
				}
				k++;
			}


    		if( idx>=since && idx<=until){

    			beta = (bdheat - kn) / unk;
		
    		}
				
    		else{
		
    			beta = (bdval - kn) / unk;
			
    		}

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
