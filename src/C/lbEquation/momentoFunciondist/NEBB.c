#include <NEBB.h>

#include <energyEqDistNode.h>

#include <stdio.h>

#include <stdlib.h>

#include <string.h>

void NEBB( basicMesh* mesh, scalar* field, scalar* Ft, char* bdname, uint bndNormal ) {


    // Determinacion del indice de frontera
    
    uint bid = 0;
    
    for( uint i = 0 ; i < mesh->bd.nbd ; i++ ) {

	if( strcmp(mesh->bd.bdNames[i], bdname) == 0 )
	    bid = i;

    }




    // Lattice constants
    
    uint Q = mesh->Q;

    scalar Ftotal[3] = { 0,0,0 };



    // Calculo sobre los elementos de esa frontera

    for( uint i = 0 ; i < mesh->bd.nbdelem[bid] ; i++ ) {


	// Indice de nodo sobre frontera
	
	uint id = mesh->bd.bdPoints[bid][i];



	// Fuerza total

	for( uint j = 0 ; j < 3 ; j++ )
	    Ftotal[j] = Ft[ id*3 + j ];


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
