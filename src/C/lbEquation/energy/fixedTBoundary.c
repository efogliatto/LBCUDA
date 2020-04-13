#include <fixedTBoundary.h>

#include <stdio.h>

#include <stdlib.h>

#include <string.h>

void fixedTBoundary( basicMesh* mesh, scalar* field, scalar* T, scalar* U, char* bdname, scalar bdval ) {


    // Determinacion del indice de frontera
    
    uint bid = 0;
    
    for( uint i = 0 ; i < mesh->bd.nbd ; i++ ) {

	if( strcmp(mesh->bd.bdNames[i], bdname) == 0 )
	    bid = i;

    }




    // Lattice constants
    
    uint Q = mesh->Q;

    scalar f_eq_bnd[9];

    scalar Uw[3] = {0,0,0};



    // Calculo sobre los elementos de esa frontera

    for( uint i = 0 ; i < mesh->bd.nbdelem[bid] ; i++ ) {


	// Indice de nodo sobre frontera
	
	uint id = mesh->bd.bdPoints[bid][i];


	// Velocidad real sobre nodo de frontera

	for(uint j = 0 ; j < 3 ; j++)
	    Uw[j] = U[id*3+j];
	
	

    }


    


    /* // Move over boundary elements */

    /* for( uint i = 0 ; i < _nodes.size() ; i++ ) { */
	

    /* 	uint id = _nodes[i]; */

    /* 	scalar Tw = unif(re) * _bndVal[i]; */



    /* 	// Density and velocity at neighbour node */

    /* 	for(uint j = 0 ; j < 3 ; j++)			 */
    /* 	    Uw[j] = _U.at(id,j); */


	

    /* 	// Equilibrium populations over boundary */

    /* 	// eeq->eqPS( f_eq_bnd, Tw, Uw, 0 ); */
    /* 	eeq->eqPS( f_eq_bnd, Tw, Uw,  eeq->heat(id) ); */


	
    /* 	// Update unknowk distributions */

    /* 	for( uint k = 1 ; k < q ; k++ ) {	    	    		       		   		     */
			
    /* 	    if( nb[id][k] == -1 ) { */

    /* 		_pdf[id][k] = f_eq_bnd[k]; */

    /* 	    } */

    /* 	} */




    /* 	// Correction constants */

    /* 	scalar beta(0), kn(0), unk(0); */

    /* 	for( uint k = 0 ; k < q ; k++ ) {	    	    		       		   		     */
			
    /* 	    if( nb[id][k] == -1 ) { */

    /* 		unk += _pdf[id][k]; */

    /* 	    } */

    /* 	    else { */

    /* 		kn += _pdf[id][k]; */

    /* 	    } */

    /* 	} */


    /* 	beta = (Tw - kn) / unk; */

    /* 	for( uint k = 0 ; k < q ; k++ ) {	    	    		       		   		     */
			
    /* 	    if( nb[id][k] == -1 ) { */

    /* 		_pdf[id][k] = beta * _pdf[id][k]; */

    /* 	    } */

    /* 	} */

	
	
	
	

    /* } */


    
    

}
