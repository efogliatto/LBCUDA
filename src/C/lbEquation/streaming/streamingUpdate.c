
#include <streamingUpdate.h>

#include <stdio.h>

void streamingUpdate( scalar* field, scalar* strupdate, basicMesh* mesh) {

    for( uint id = 0 ; id < mesh->nPoints ; id++ ) {

        // Copia en cada componente de field

        for( uint j = 0 ; j < mesh->Q ; j++ ) {
            
            field[ id*mesh->Q + j] = strupdate[ id*mesh->Q + j] ;
        
        }

    }

}