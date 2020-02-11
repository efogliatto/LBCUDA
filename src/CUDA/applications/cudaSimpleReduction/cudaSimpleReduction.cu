/*

  simpleReduction

  Suma de componentes de funciones de distribuci\'on por nodo

 */


extern "C" {
    
#include <latticeMesh.h>

#include <basic.h>

}

#include <stdio.h>

#include <cuda_runtime.h>

#include <cudaTest.h>

#include <cudaLatticeMesh.h>

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
    



    

    // Reduccion

    printf(" Aplicando reducción en %d iteraciones\n\n", nit);

    timeInfo Time;

    startTime(&Time);

    for( uint k = 0 ; k < nit ; k++ ) {
	
    	/* zerothMoment<<<ceil(mesh.nPoints/xgrid)+1,xgrid>>>(deviceField, deviceSum, cmesh.nPoints, cmesh.Q); 
    	threadedZerothMoment<<<xgrid,ceil((mesh.nPoints+1)/xgrid)>>>(deviceField, deviceSum, cmesh.nPoints, cmesh.Q);*/
	thomasModel<<<ceil(mesh.nPoints/xgrid)+1,xgrid>>>(deviceField, deviceSum, cmesh.nPoints, cmesh.Q);

	cudaDeviceSynchronize();
	
    }


    scalar elap = elapsedTime(&Time);
    
    printf( "\n   Reduccion finalizada en %f segundos\n", elap );
    printf( "\n   Tiempo promedio de ejecución por iteración: %g segundos\n\n", elap/nit );    
    


    
    // Resultados vuelta al host
    
    cuscalar* dsum = (cuscalar*)malloc( mesh.nPoints * sizeof(cuscalar) );

    cudaMemcpy( dsum, deviceSum, mesh.nPoints*sizeof(cuscalar), cudaMemcpyDeviceToHost );


    

    // Verificacion de calculo contra version de CPU

    zerothMomentCPU(sum, field, &mesh);

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
