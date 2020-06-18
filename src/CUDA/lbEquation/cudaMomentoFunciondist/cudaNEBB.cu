#include <cudaNEBB.h>

#include <cudaEnergyEqDistNode.h>

#include <stdio.h>

extern "C" __global__ void cudaNEBB( cuscalar* field,
				     cuscalar* Ft,
				     int* bdPoints,
				     uint bid,
				     uint bndNormal,
				     uint maxNbd,
				     uint Q ) {

    
    // Thread index
    
    int idx = threadIdx.x + blockIdx.x*blockDim.x;


    // Calcular solo si el nodo pertenece a esta frontera
    
    if( ( idx >= (bid * maxNbd) )  &&  ( idx < (bid * maxNbd  + maxNbd) )  ) {


	// Indice de nodo sobre frontera
	
	int id = bdPoints[idx];

	if( id != -1 ) {


	    // Fuerza total

	    cuscalar Ftotal[3] = {0,0,0};

		uint j=0;
	    while( j < 3 ){
			Ftotal[j] = Ft[ id*3 + j ];
			j++;	
		}

	    switch( bndNormal ) {


	    case 0:  // X0

		field[id*Q+1] = field[id*Q+3];

		field[id*Q+5] = field[id*Q+7] + 0.5 * (  field[id*Q+4] - field[id*Q+2] ) + 0.25*(Ftotal[0]+Ftotal[1]);

		field[id*Q+8] = field[id*Q+6] - 0.5 * (  field[id*Q+4] - field[id*Q+2] ) + 0.25*(Ftotal[0]-Ftotal[1]);

		break;


	    case 1:  // X1

		field[id*Q+3] = field[id*Q+1];

		field[id*Q+7] = field[id*Q+5] - 0.5 * (  field[id*Q+4] - field[id*Q+2] ) - 0.25*(Ftotal[0]+Ftotal[1]);

		field[id*Q+6] = field[id*Q+8] + 0.5 * (  field[id*Q+4] - field[id*Q+2] ) - 0.25*(Ftotal[0]-Ftotal[1]);

		break;


	    case 2:  // Y0

		field[id*Q+2] = field[id*Q+4];

		field[id*Q+5] = field[id*Q+7] - 0.5 * (  field[id*Q+1] - field[id*Q+3] ) - 0.25*(Ftotal[0]+Ftotal[1]);

		field[id*Q+6] = field[id*Q+8] + 0.5 * (  field[id*Q+1] - field[id*Q+3] ) + 0.25*(Ftotal[0]-Ftotal[1]);

		break;


	    case 3:  // Y1

		field[id*Q+4] = field[id*Q+2];

		field[id*Q+7] = field[id*Q+5] + 0.5 * (  field[id*Q+1] - field[id*Q+3] ) + 0.25*(Ftotal[0]+Ftotal[1]);

		field[id*Q+8] = field[id*Q+6] - 0.5 * (  field[id*Q+1] - field[id*Q+3] ) - 0.25*(Ftotal[0]-Ftotal[1]);		

		break;	    
	    

	    }
	    


	}


    }
    

}
