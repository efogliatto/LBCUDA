/*

  cudaNbReduction

  Suma de componentes de funciones de distribuci\'on en los vecinos, y reduccion por nodo

 */


extern "C" {
    
#include <latticeMesh.h>

#include <basic.h>

}

#include <stdio.h>

#include <cuda_runtime.h>

#include <cudaTest.h>

#include <cudaLatticeMesh.h>




int main(int argc, char** argv) {


    
    
    printf( "                    \n" );
    printf( "     o-----o-----o  \n" );
    printf( "     | -   |   - |  \n" );
    printf( "     |   - | -   |                cudaNbReduction\n" );
    printf( "     o<----o---->o  \n" );
    printf( "     |   - | -   |  Operacion de reduccion en GPU sobre nodos vecinos\n" );
    printf( "     | -   |   - |  \n" );
    printf( "     o-----o-----o  \n\n" );


    // Argumentos:
    //
    // - argv[1] = numero de iteraciones

    uint nit = atoi( argv[1] );
    


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

    cuscalar* sum = (cuscalar*)malloc( mesh.nPoints * sizeof(cuscalar) );




    
    // Inicializacion (puede ser otra)

    for( uint i = 0 ; i < fsize ; i++ )
    	field[i] = i;

    
    for( uint i = 0 ; i < mesh.nPoints ; i++ )
    	sum[i] = 1.0;



    
    // Alocacion de memoria en el device y copia

    cuscalar* deviceField;

    cudaMalloc( (void**)&deviceField, fsize*sizeof(cuscalar) );

    cudaMemcpy( deviceField, field, fsize*sizeof(cuscalar), cudaMemcpyHostToDevice );


    cuscalar* deviceSum;

    cudaMalloc( (void**)&deviceSum, mesh.nPoints*sizeof(cuscalar) );

    cudaMemcpy( deviceSum, sum, mesh.nPoints*sizeof(cuscalar), cudaMemcpyHostToDevice );    
    





    
    /**************************************/
    /*            Neighbours              */
    /**************************************/

    int* deviceNb;

    {

	// First create one-dimensional array

	int* hostNb = (int*)malloc( mesh.nPoints * mesh.Q * sizeof(int) );

	for( uint i = 0 ; i < mesh.nPoints ; i++ ) {

	    for( uint j = 0 ; j < mesh.Q ; j++ ) {

		hostNb[ i*mesh.Q + j ] = mesh.nb[i][j];

	    }

	}

	

	// Copy to device
    
	cudaMalloc( (void**)&deviceNb, mesh.nPoints*mesh.Q*sizeof(int) );

	cudaMemcpy( deviceNb, hostNb, mesh.nPoints*mesh.Q*sizeof(int), cudaMemcpyHostToDevice );

	free(hostNb);

    }
    
    

    // Reduccion

    printf(" Aplicando reducción en %d iteraciones\n\n", nit);

    timeInfo Time;

    startTime(&Time);

    for( uint k = 0 ; k < nit ; k++ )
    	nbReduction<<<mesh.nPoints,1>>>(deviceField, deviceSum, deviceNb, cmesh.nPoints, cmesh.Q);


    scalar elap = elapsedTime(&Time);
    
    printf( "\n   Reduccion finalizada en %f segundos\n", elap );
    printf( "\n   Tiempo promedio de ejecución por iteración: %g segundos\n\n", elap/nit );    


    

    
    // Resultados vuelta al host
    
    cuscalar* dsum = (cuscalar*)malloc( mesh.nPoints * sizeof(cuscalar) );

    cudaMemcpy( dsum, deviceSum, mesh.nPoints*sizeof(cuscalar), cudaMemcpyDeviceToHost );
    
    

    // Verificacion de calculo contra version de CPU

    nbReductionCPU(sum, field, &mesh);

    {
	
    	uint eq = 0;

    	for(uint i = 0 ; i < mesh.nPoints ; i++) {

    	    if(dsum[i] != sum[i])
    	    	eq = 1;

    	}

    	if(eq != 0)
    	    printf( " Los resultados de host y device difieren!\n " );
    
    }

    
    // Limpieza de memoria

    free( field );

    free( sum );

    freeBasicMesh( &mesh );

    cudaFree( deviceField );

    cudaFree( deviceSum );
    
    return 0;

}
