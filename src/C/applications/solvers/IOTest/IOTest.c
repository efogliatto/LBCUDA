/*

  IOTest

  Prueba de escritura a formato Ensight

 */



#include <latticeMesh.h>

#include <IO.h>

#include <basic.h>

#include <stdio.h>


int main(int argc, char** argv) {

    
    printf( "                    \n" );
    printf( "     o-----o-----o  \n" );
    printf( "     | -   |   - |  \n" );
    printf( "     |   - | -   |                IOTest\n" );
    printf( "     o<----o---->o  \n" );
    printf( "     |   - | -   |  Prueba de escritura en formato Ensight\n" );
    printf( "     | -   |   - |  \n" );
    printf( "     o-----o-----o  \n\n" );

 


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



    // Alocacion de arreglos para variables macroscopicas

    scalar* rho = (scalar*)malloc( mesh.nPoints * sizeof(scalar) );

    scalar* T = (scalar*)malloc( mesh.nPoints * sizeof(scalar) );

    scalar* U = (scalar*)malloc( mesh.nPoints * 3 * sizeof(scalar) );    


    
    // Inicializacion (puede ser otra)

    for( uint i = 0 ; i < mesh.nPoints ; i++ )
    	T[i] = 0.9 / 27.0;

    for( uint i = 0 ; i < mesh.nPoints ; i++ )
    	rho[i] = 1.0 / 12.0;

    for( uint i = 0 ; i < mesh.nPoints ; i++ ){
	for( uint j = 0 ; j < 3 ; j++ ){
	    U[i*3+j] = j;
	}
    }




    // Escritura de campos (paso 1)

    writeMeshToEnsight( &mesh );

    writeScalarToEnsight("rho", rho, &mesh, 0);

    writeScalarToEnsight("T", T, &mesh, 0);

    writeVectorToEnsight("U", U, &mesh, 0);





    // Cambio de valores

    for( uint i = 0 ; i < mesh.nPoints ; i++ )
    	T[i] = 2*0.9 / 27.0;

    for( uint i = 0 ; i < mesh.nPoints ; i++ )
    	rho[i] = 2.0 / 12.0;

    for( uint i = 0 ; i < mesh.nPoints ; i++ ){
	for( uint j = 0 ; j < 3 ; j++ ){
	    U[i*3+j] = 2*j;
	}
    }



    // Escritura de campos (paso 2)

    writeScalarToEnsight("rho", rho, &mesh, 1);

    writeScalarToEnsight("T", T, &mesh, 1);

    writeVectorToEnsight("U", U, &mesh, 1);
    



    // Actualizacion de caso maestro

    char scfields[2][100] = {"rho", "T"};

    char vfields[1][100] = {"U"};

    uint timeList[2] = {0,100};

    updateCaseFile(scfields, 2, vfields, 1, timeList, 2);





    // Limpieza de memoria

    free( T );

    free( rho );

    free( U );

    freeBasicMesh( &mesh );
    
    return 0;

}
