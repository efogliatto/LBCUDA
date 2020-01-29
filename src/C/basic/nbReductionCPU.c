#include <nbReductionCPU.h>

#include <stdio.h>

void nbReductionCPU(scalar* sum, scalar* field, basicMesh* mesh) {


    for( uint i = 0 ; i < mesh->nPoints ; i++ ) {

	scalar nodesum = 0;	

	// Reduccion en cada vecino

	for( uint j = 0 ; j < mesh->Q ; j++ ) {

	    // El indice del nodo vecino es nb[i][j]
	    // Por lo tanto para iterar sobre sus componentes usando l es
	    //
	    //    for( uint l = 0 ; l < mesh->Q ; l++ )
	    //	nbsum += field[ mesh->nb[i][j]*mesh->Q + l  ];
	    //
		
	    scalar nbsum = 0;

	    int nbid = mesh->nb[i][j];
	    
	    if( nbid != -1 ) {

		for( uint l = 0 ; l < mesh->Q ; l++ ) {

		    nbsum += field[ nbid*mesh->Q + l  ];

		}

	    }

	    nodesum += nbsum;


	}


	sum[i] = nodesum;

    }
    

}

