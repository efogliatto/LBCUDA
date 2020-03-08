/*

  simpleReduction

  Suma de componentes de funciones de distribuci\'on por nodo

 */


extern "C" {
    
#include <latticeMesh.h>

#include <basic.h>

#include <exampleModel.h>   

#include <momentoFunciondist.h>   

#include <momentoVelocity.h>

#include <fuerza.h>   

}

#include <stdio.h>

#include <cuda_runtime.h>

#include <cudaTest.h>

#include <cudaLatticeMesh.h>

#include <cudaExampleModel.h>

#include <cudaMomentoFunciondist.h>

#include <cudaFuerza.h>

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
    
    // Parametros del modelo D2Q9

    int a = 1;

    int b = 4;

    cuscalar G = -1.0; 

    cuscalar c = 1.0; 

    cuscalar cs_2 = ( 1.0/3.0 ); 

    scalar sigma = 1.0;

    // Aceleracion del problema

    cuscalar g[3] = {0,0,0};

    

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

    cuscalar* rho = (cuscalar*)malloc( mesh.nPoints * sizeof(cuscalar) ); //Density

    cuscalar* U = (cuscalar*)malloc( 3 * mesh.nPoints * sizeof(cuscalar) ); // Velocity macroscopic    

    cuscalar* Temp = (cuscalar*)malloc( mesh.nPoints * sizeof(cuscalar) ); // Temperature

    cuscalar* fint = (cuscalar*)malloc( mesh.nPoints * 3 * sizeof(cuscalar) ); // Interaction force

    cuscalar* f = (cuscalar*)malloc( mesh.nPoints * 3 * sizeof(cuscalar) ); // Total force ( volumetric add interaction ) 

       
    // Inicializacion (puede ser otra)

    for( uint i = 0 ; i < fsize ; i++ )
        field[i] = 1.0;
        
    for( uint i = 0 ; i < mesh.nPoints ; i++ )
        rho[i] = 1.0;
    
    
    /*for( uint i = 0 ; i < (mesh.nPoints/2) ; i++ )
        rho[i] = 1.0;
        
    for( uint i = (mesh.nPoints/2) ; i < mesh.nPoints ; i++ )
    	rho[i] = 2.0;    */

    for( uint i = 0 ; i < (3*mesh.nPoints) ; i++ )
    	U[i] = 2.0;

    for( uint i = 0 ; i < mesh.nPoints ; i++ )
    	Temp[i] = 1e-2;

    for( uint i = 0 ; i < (3*mesh.nPoints) ; i++ )
    	fint[i] = 5.0;

    for( uint i = 0 ; i < (3*mesh.nPoints) ; i++ )
    	f[i] = 8.0;

        
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


    cuscalar* deviceT;

    cudaMalloc( (void**)&deviceT, mesh.nPoints*sizeof(cuscalar) );

    cudaMemcpy( deviceT, Temp, mesh.nPoints*sizeof(cuscalar), cudaMemcpyHostToDevice );


    cuscalar* deviceFint;

    cudaMalloc( (void**)&deviceFint, 3*mesh.nPoints*sizeof(cuscalar) );

    cudaMemcpy( deviceFint, fint, 3*mesh.nPoints*sizeof(cuscalar), cudaMemcpyHostToDevice );


    cuscalar* deviceF;

    cudaMalloc( (void**)&deviceF, 3*mesh.nPoints*sizeof(cuscalar) );

    cudaMemcpy( deviceF, f, 3*mesh.nPoints*sizeof(cuscalar), cudaMemcpyHostToDevice );


    
    // Factores de relajacion para colision

//    exampleModelCoeffs relax;

    momentoModelCoeffs relax;

    for( uint i = 0 ; i < 9 ; i++ )
	    relax.Tau[i] = 1;


    
    cuscalar* deviceTau;

    cudaMalloc( (void**)&deviceTau, 9*sizeof(cuscalar) );

    cudaMemcpy( deviceTau, relax.Tau, 9*sizeof(cuscalar), cudaMemcpyHostToDevice );    


    cuscalar delta_t_cu = 1.0;
    

    // Reduccion

    printf(" Colisión en %d iteraciones\n\n", nit);

    timeInfo Time;

    startTime(&Time);

    for( uint k = 0 ; k < nit ; k++ ) {
	
//    	cudaExampleCollision<<<ceil(mesh.nPoints/xgrid)+1,xgrid>>>( deviceField, deviceRho, deviceU, deviceTau, cmesh.lattice.M, cmesh.lattice.invM, cmesh.nPoints, cmesh.Q );

	    cudaMomentoCollision<<<ceil(mesh.nPoints/xgrid)+1,xgrid>>>( deviceField, deviceRho, deviceU, deviceF, deviceFint, deviceT, deviceTau, cmesh.lattice.M, cmesh.lattice.invM, cmesh.nPoints, cmesh.Q, delta_t_cu, a, b, c, cs_2, G, sigma);

        cudaDeviceSynchronize();
        


//        cudaFuerzaFuerzaint<<<ceil(mesh.nPoints/xgrid)+1,xgrid>>>( deviceFint, deviceRho, deviceT, cmesh.nPoints, cmesh.Q,  cmesh.lattice.vel, cmesh.nb, G, c, cs_2, a, b)   ;

    //    cudaDeviceSynchronize();

    //     cudaFuerzaFuerzatotal<<<ceil(mesh.nPoints/xgrid)+1,xgrid>>>( deviceF, deviceFint, deviceRho, g, cmesh.nPoints);	

    //	cudaDeviceSynchronize();
/*
        cudaMomentoVelocity<<<ceil(mesh.nPoints/xgrid)+1,xgrid>>>(deviceField, deviceRho, deviceU, cmesh.lattice.vel, cmesh.nPoints, cmesh.Q, delta_t_cu );

    	cudaDeviceSynchronize();

        cudaMomentoDensity<<<ceil(mesh.nPoints/xgrid)+1,xgrid>>>( deviceField, deviceRho, cmesh.nPoints, cmesh.Q);  

    	cudaDeviceSynchronize();

        */

	
    }

    scalar delta_t = 1.0;	
    scalar elap = elapsedTime(&Time);
    
    printf( "\n   Colisión finalizada en %f segundos\n", elap );
    printf( "\n   Tiempo promedio de ejecución por iteración: %g segundos\n\n", elap/nit );
    


    
    // Resultados vuelta al host
    
    cuscalar* dcol = (cuscalar*)malloc( fsize * sizeof(cuscalar) );

    cudaMemcpy( dcol, deviceField, fsize*sizeof(cuscalar), cudaMemcpyDeviceToHost );

/*-----------------------------------------------------------------------------------------*/
/*
    cuscalar* dRho = (cuscalar*)malloc( mesh.nPoints * sizeof(cuscalar) );

    cudaMemcpy( dRho, deviceRho, mesh.nPoints*sizeof(cuscalar), cudaMemcpyDeviceToHost ); 


    cuscalar* dU = (cuscalar*)malloc( 3 * mesh.nPoints * sizeof(cuscalar) );

    cudaMemcpy( dU, deviceU, 3*mesh.nPoints*sizeof(cuscalar), cudaMemcpyDeviceToHost ); 


    cuscalar* dT = (cuscalar*)malloc( mesh.nPoints * sizeof(cuscalar) ); 

    cudaMemcpy( dT, deviceT, mesh.nPoints*sizeof(cuscalar), cudaMemcpyDeviceToHost ); 


 */ cuscalar* dFint = (cuscalar*)malloc( mesh.nPoints * 3 * sizeof(cuscalar) );

    cudaMemcpy( dFint, deviceFint, 3*mesh.nPoints*sizeof(cuscalar), cudaMemcpyDeviceToHost ); 
/*

    cuscalar* dF = (cuscalar*)malloc( mesh.nPoints * 3 * sizeof(cuscalar) );

    cudaMemcpy( dF, deviceF, 3*mesh.nPoints*sizeof(cuscalar), cudaMemcpyDeviceToHost ); 

*/
   
/*-----------------------------------------------------------------------------------------*/



    // Verificacion de calculo contra version de CPU

//    exampleCollision( &mesh, &relax, field, rho, U );

    momentoCollision( &mesh, &relax, field, rho, U, f, fint, Temp, delta_t, a, b, c, cs_2, G, sigma);

							      // A continuacion se calculan el resto de los parametroz para ir actualizandolos
    

    
    //fuerzaFuerzaint(fint, rho, Temp , &mesh, G, c, cs_2, a, b);
/*
    fuerzaFuerzatotal(f, fint, rho, g, &mesh); 

    momentoVelocity( rho,  U, field, &mesh, delta_t, f);

    momentoDensity( rho, field, &mesh);  

    fuerzaS(S, f, fint, U, psi, sigma, relax.Tau, &mesh, delta_t);
*/

    {
	
    	uint eq = 0;

        printf( "    CUDA \t \t     C \t \t \t    DIFIEREN \n\n");

    	for(uint i = 0 ; i < fsize ; i++) {
        //for(uint i = 0 ; i <   mesh.nPoints*3 ; i++) {            
            eq = 0;
            cuscalar diferencia = fabs(dcol[i] - field[i]);
          
            if( diferencia > 0.000001 )
                eq = 1;


            //if(dcol[i] != field[i])
              //  eq = 1;
            printf( "%lf \t %lf \t \t \t %d \n", dcol[i],field[i],eq);
    	    //printf( "%f \t  %f  \t \t \t %d \n\n", dFint[i],fint[i],eq);
//	    printf( "%d \n", eq);	
//	    printf( "%f \n", S[i]);	

    	}

    	if(eq != 0)
    	    printf( "\n Los resultados de host y device difieren!\n\n " );
    
    }

    printf( "\n\n Comienza la limpieza de memoria!\n\n " );

    
    // Limpieza de memoria host

    freeBasicMesh( &mesh );

    free( field );

    free( rho );

    free( U ); 

    free( Temp );

    free( f );   

    free( fint );

    // Limpieza de memoria device

    cudaFree( deviceField );

    cudaFree( deviceRho );

    cudaFree( deviceU );

    cudaFree( deviceT );

    cudaFree( deviceFint );

    cudaFree( deviceF );

    cudaFree( deviceTau);

    // Limpieza de memoria host de comparacion

    free( dcol );


    
printf( "\n\n Finaliza la limpieza de memoria!\n\n " );

   
    return 0;

}
