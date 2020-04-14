#include <boundaryIndex.h>

#include <string.h>

#include <stdio.h>


__host__ void boundaryIndex( basicMesh* mesh, const char* bdname, uint* idx) {

    
    // Determinacion del indice de frontera
    
    *idx = 0;
    
    for( uint i = 0 ; i < mesh->bd.nbd ; i++ ) {

	if( strcmp(mesh->bd.bdNames[i], bdname) == 0 )
	    *idx = i;

    }


}
