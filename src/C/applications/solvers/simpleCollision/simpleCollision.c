/*

  simpleCollision

  Colisión de modelo simplificado en todos los nodos

 */



#include <latticeMesh.h>

#include <exampleModel.h>

#include <basic.h>

#include <stdio.h>


int main(int argc, char** argv) {

    
    printf( "                    \n" );
    printf( "     o-----o-----o  \n" );
    printf( "     | -   |   - |  \n" );
    printf( "     |   - | -   |                simpleCollision\n" );
    printf( "     o<----o---->o  \n" );
    printf( "     |   - | -   |  Operacion de colisión sobre funcion de distribucion\n" );
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


    // Alocacion de arreglos para variables macroscopicas

    scalar* rho = (scalar*)malloc( mesh.nPoints * sizeof(scalar) );

    scalar* U = (scalar*)malloc( mesh.nPoints * 3 * sizeof(scalar) );    


    
    // Inicializacion (puede ser otra)

    for( uint i = 0 ; i < fsize ; i++ )
    	field[i] = 0;

    for( uint i = 0 ; i < mesh.nPoints ; i++ )
    	rho[i] = 1;

    for( uint i = 0 ; i < (mesh.nPoints * 3) ; i++ )
    	U[i] = 0;



    // Factores de relajacion para colision

    exampleModelCoeffs relax;

    for( uint i = 0 ; i < 9 ; i++ )
	relax.Tau[i] = 1;
    


    // Colision

    printf(" Aplicando colisión en %d iteraciones\n\n", nit);

    timeInfo Time;

    startTime(&Time);

    for( uint k = 0 ; k < nit ; k++ )
    	exampleCollision( &mesh, &relax, field, rho, U );



    

    scalar elap = elapsedTime(&Time);

    printf( "\n   Colisión finalizada en %f segundos\n", elap );
    printf( "\n   Tiempo promedio de ejecución por iteración: %g segundos\n\n", elap/nit );



    // Limpieza de memoria

    free( field );

    free( rho );

    free( U );

    freeBasicMesh( &mesh );
    
    return 0;

}
