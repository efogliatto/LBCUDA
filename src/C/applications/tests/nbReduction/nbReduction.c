/*

  nbReduction

  Suma de componentes de funciones de distribuci\'on en cada vecino, y reduccion

 */



#include <latticeMesh.h>

#include <basic.h>

#include <stdio.h>


int main(int argc, char** argv) {

    
    printf( "                    \n" );
    printf( "     o-----o-----o  \n" );
    printf( "     | -   |   - |  \n" );
    printf( "     |   - | -   |                            nbReduction\n" );
    printf( "     o<----o---->o  \n" );
    printf( "     |   - | -   |  Operacion de reduccion sobre funcion de distribucion sobre vecinos\n" );
    printf( "     | -   |   - |  \n" );
    printf( "     o-----o-----o  \n\n" );


    // Argumentos:
    //
    // - argv[1] = numero de iteraciones

    uint nit = atoi( argv[1] );
    


    // Lectura de malla

    basicMesh mesh = readBasicMesh();


    // Alocacion de funcion de distribucion como arreglo unidimensional
    //
    // Si se desea acceder a los componentes de field usando dos indices,
    // entonces puede hacerse algo como
    //
    // for( i = 0 ; i < mesh.nPoints ; i++)
    //     for( j = 0 ; j < mesh.Q ; j++)
    //         idx = i*mesh.Q + j;

    uint fsize = mesh.nPoints * mesh.Q;
    
    scalar* field = (scalar*)malloc( fsize * sizeof(scalar) );


    // Alocacion de arreglo de salida

    scalar* sum = (scalar*)malloc( mesh.nPoints * sizeof(scalar) );


    
    // Inicializacion (puede ser otra)

    for( uint i = 0 ; i < fsize ; i++ )
	field[i] = i;

    for( uint i = 0 ; i < mesh.nPoints ; i++ )
	sum[i] = 1.0;



    // Reduccion

    printf(" Aplicando reducción en %d iteraciones\n\n", nit);

    timeInfo Time;

    startTime(&Time);

    for( uint k = 0 ; k < nit ; k++ )
    	nbReductionCPU(sum, field, &mesh);

    


    scalar elap = elapsedTime(&Time);

    printf( "\n   Reduccion finalizada en %f segundos\n", elap );
    printf( "\n   Tiempo promedio de ejecución por iteración: %g segundos\n\n", elap/nit );        



    // Limpieza de memoria

    free( field );

    free( sum );

    freeBasicMesh( &mesh );
    
    return 0;

}
