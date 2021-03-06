/*

  simpleReduction

  Suma de componentes de funciones de distribuci\'on por nodo

 */


extern "C" {
    
#include <latticeMesh.h>

#include <basic.h>

#include <exampleModel.h>    

}

#include <stdio.h>

#include <cuda_runtime.h>

#include <cudaTest.h>

#include <cudaLatticeMesh.h>

#include <cudaExampleModel.h>

#include <math.h>





int main(int argc, char** argv) {


    
    
    printf( "                    \n" );
    printf( "     o-----o-----o  \n" );
    printf( "     | -   |   - |  \n" );
    printf( "     |   - | -   |                cuSimpleReduction\n" );
    printf( "     o<----o---->o  \n" );
    printf( "     |   - | -   |  Operacion de reduccion en GPU  sobre funcion de distribucion\n" );
    printf( "     | -   |   - |  \n" );
    printf( "     o-----o-----o  \n\n" );


    // Argumentos:
    //
    // - argv[1] = numero de iteraciones
    // - argv[2] = xgrid

    uint nit  = atoi( argv[1] );

    int xgrid = atoi( argv[2] );
    


    // Informacion sobre el device

    cudaDeviceProp prop;

    {
	int count;
	
	cudaGetDeviceCount( &count );
	
	for (int i=0; i< count; i++)
	    cudaGetDeviceProperties( &prop, i );

	printf( "\n -- Informacion general del device --  \n\n" );
	printf( "  Nombre: %s\n", prop.name );
	printf( "  Compute capability: %d.%d\n", prop.major, prop.minor );
	printf( "  Total global mem: %.2f GB\n", (float)prop.totalGlobalMem / 1000000000 );
	printf( "  Total constant Mem: %ld\n", prop.totalConstMem );
	printf( "\n\n" );

    }
    

    

    // Lectura de malla

    basicMesh mesh = readBasicMesh();

    cudaBasicMesh cmesh;

    hostToDeviceMesh( &cmesh, &mesh );




    // Alocacion de funcion de distribucion como arreglo unidimensional
    //
    // Si se desea acceder a los componentes de field usando dos indices,
    // entonces puede hacerse algo como
    //
    // for( i = 0 ; i < mesh.nPoints ; i++)
    //     for( j = 0 ; j < mesh.Q ; j++)
    //         idx = i*mesh.Q + j;

    uint fsize = mesh.nPoints * mesh.Q;
    
    cuscalar* field = (cuscalar*)malloc( fsize * sizeof(cuscalar) );


    
    // Alocacion de arreglo de salida

    cuscalar* rho = (cuscalar*)malloc( mesh.nPoints * sizeof(cuscalar) );

    cuscalar* U = (cuscalar*)malloc( 3 * mesh.nPoints * sizeof(cuscalar) );    


    
    // Inicializacion (puede ser otra)

    for( uint i = 0 ; i < fsize ; i++ )
    	field[i] = 1;

    
    for( uint i = 0 ; i < mesh.nPoints ; i++ )
    	rho[i] = 1.0;

    for( uint i = 0 ; i < (3*mesh.nPoints) ; i++ )
    	U[i] = 0;


    
    // Alocacion de memoria en el device y copia

    cuscalar* deviceField;

    cudaMalloc( (void**)&deviceField, fsize*sizeof(cuscalar) );

    cudaMemcpy( deviceField, field, fsize*sizeof(cuscalar), cudaMemcpyHostToDevice );


    cuscalar* deviceRho;

    cudaMalloc( (void**)&deviceRho, mesh.nPoints*sizeof(cuscalar) );

    cudaMemcpy( deviceRho, rho, mesh.nPoints*sizeof(cuscalar), cudaMemcpyHostToDevice );


    cuscalar* deviceU;

    cudaMalloc( (void**)&deviceU, 3*mesh.nPoints*sizeof(cuscalar) );

    cudaMemcpy( deviceU, U, 3*mesh.nPoints*sizeof(cuscalar), cudaMemcpyHostToDevice );




    // Factores de relajacion para colision

    exampleModelCoeffs relax;

    for( uint i = 0 ; i < 9 ; i++ )
	relax.Tau[i] = 1;


    
    cuscalar* deviceTau;

    cudaMalloc( (void**)&deviceTau, 9*sizeof(cuscalar) );

    cudaMemcpy( deviceTau, relax.Tau, 9*sizeof(cuscalar), cudaMemcpyHostToDevice );    



    

    // Reduccion

    printf(" Colisión en %d iteraciones\n\n", nit);

    timeInfo Time;

    startTime(&Time);

    for( uint k = 0 ; k < nit ; k++ ) {
	
    	cudaExampleCollision<<<ceil(mesh.nPoints/xgrid)+1,xgrid>>>( deviceField, deviceRho, deviceU, deviceTau, cmesh.lattice.M, cmesh.lattice.invM, cmesh.nPoints, cmesh.Q );

    	cudaDeviceSynchronize();
	
    }


    scalar elap = elapsedTime(&Time);
    
    printf( "\n   Colisión finalizada en %f segundos\n", elap );
    printf( "\n   Tiempo promedio de ejecución por iteración: %g segundos\n\n", elap/nit );
    


    
    // Resultados vuelta al host
    
    cuscalar* dcol = (cuscalar*)malloc( fsize * sizeof(cuscalar) );

    cudaMemcpy( dcol, deviceField, fsize*sizeof(cuscalar), cudaMemcpyDeviceToHost );


    

    // Verificacion de calculo contra version de CPU

    exampleCollision( &mesh, &relax, field, rho, U );

    {
	
    	uint eq = 0;

    	for(uint i = 0 ; i < fsize ; i++) {

    	    if(dcol[i] != field[i])
    		eq = 1;

    	}

    	if(eq != 0)
    	    printf( " Los resultados de host y device difieren!\n " );
    
    }

    
    // Limpieza de memoria

    free( field );

    free( rho );

    free( U );    

    freeBasicMesh( &mesh );

    cudaFree( deviceField );

    cudaFree( deviceRho );

    cudaFree( deviceU );
    
    
    return 0;

}
