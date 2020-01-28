/*

  simpleReduction

  Suma de componentes de funciones de distribuci\'on por nodo

 */



#include <latticeMesh.h>

#include <basic.h>

#include <stdio.h>

#include <cuda_runtime.h>



int main(int argc, char** argv) {

    
    printf( "                    \n" );
    printf( "     o-----o-----o  \n" );
    printf( "     | -   |   - |  \n" );
    printf( "     |   - | -   |                simpleReduction\n" );
    printf( "     o<----o---->o  \n" );
    printf( "     |   - | -   |  Operacion de reduccion sobre funcion de distribucion\n" );
    printf( "     | -   |   - |  \n" );
    printf( "     o-----o-----o  \n\n" );


    // Argumentos:
    //
    // - argv[1] = numero de iteraciones
    // - argv[2] = tamanio de bloque

    uint nit = atoi( argv[1] );

    uint blsize = atoi( argv[2] );
    


    // Lectura de malla

    basicMesh mesh = readBasicMesh();


    /* // Alocacion de funcion de distribucion como arreglo unidimensional */
    /* // */
    /* // Si se desea acceder a los componentes de field usando dos indices, */
    /* // entonces puede hacerse algo como */
    /* // */
    /* // for( i = 0 ; i < mesh.nPoints ; i++) */
    /* //     for( j = 0 ; j < mesh.Q ; j++) */
    /* //         idx = i*mesh.Q + j; */

    /* uint fsize = mesh.nPoints * mesh.Q; */
    
    /* cuscalar* field = (cuscalar*)malloc( fsize * sizeof(cuscalar) ); */


    /* // Alocacion de arreglo de salida */

    /* cuscalar* sum = (cuscalar*)malloc( mesh.nPoints * sizeof(cuscalar) ); */


    
    /* // Inicializacion (puede ser otra) */

    /* for( uint i = 0 ; i < fsize ; i++ ) */
    /* 	field[i] = i; */





    
    /* // Alocacion de memoria en el device y copia */

    /* cuscalar* deviceField; */

    /* cudaMalloc( (void**)&deviceField, fsize*sizeof(cuscalar) ); */


    /* cuscalar* deviceSum; */

    /* cudaMalloc( (void**)&deviceSum, mesh.nPoints*sizeof(cuscalar) ); */

    



    /* // Reduccion */

    /* printf(" Aplicando reducción en %d iteraciones\n\n", nit); */

    /* timeInfo Time; */

    /* startTime(&Time); */

    /* for( uint k = 0 ; k < nit ; k++ ) { */

	

    /* } */


    /* printf( "\n   Reduccion finalizada en %f segundos\n\n", elapsedTime(&Time) ); */




    
    /* // Limpieza de memoria */

    /* free( field ); */

    /* free( sum ); */

    /* freeBasicMesh( &mesh ); */

    /* cudaFree( deviceField ); */

    /* cudaFree( deviceSum );     */
    
    return 0;

}
