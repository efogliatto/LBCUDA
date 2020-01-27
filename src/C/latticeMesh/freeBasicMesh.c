#include <freeBasicMesh.h>

#include <stdlib.h>


void freeBasicMesh( basicMesh* mesh) {

    
    // Liberacion de puntos
    
    for( uint i = 0 ; i < mesh->nPoints ; i++ )
	free( mesh->points[i] );

    free( mesh->points );



    // Liberacion de vecinos
    
    for( uint i = 0 ; i < mesh->nPoints ; i++ )
	free( mesh->nb[i] );

    free( mesh->nb );    
	

}
