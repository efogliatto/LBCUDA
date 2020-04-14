
#include <streamingNbReduction.h>

#include <stdio.h>

void streamingNbReduction(scalar* sum, scalar* field, basicMesh* mesh) {

    for( uint id = 0 ; id < mesh->nPoints ; id++ ) {

        // Reduccion en cada vecino

        for( uint j = 0 ; j < mesh->Q ; j++ ) {

            int nbid = mesh->nb[id][j];
            
            // caso de vecinos interiores

            if( nbid != -1 ) {

                // Reduccion en cada componente de field

                for( uint k = 0 ; k < mesh->Q ; k++ ) {

                    sum[ id*mesh->Q + k] += field[ nbid*mesh->Q + k];

                }

            }

            // caso de vecinos en bordes

            if ( nbid == -1){

                for( uint k = 0 ; k < mesh->Q ; k++ ) {
                    
                    sum[ id*mesh->Q + k] += 2*field[ id*mesh->Q + k] + field[ mesh->nb[id][(mesh->lattice.reverse[j])]*mesh->Q + k];

                }                
           
            }

            // falta diferenciar el node de las esquinas

        }

    }

}