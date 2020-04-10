/*

  Maxwell construction

  Construccion de Maxwell isotermica

 */


extern "C" {
    
#include <latticeMesh.h>

#include <basic.h>

#include <exampleModel.h>   

#include <momentoFunciondist.h>   

#include <momentoVelocity.h>

#include <fuerza.h>

#include <IO.h>

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
    printf( "     |   - | -   |                cudaMaxwellConstruction \n" );
    printf( "     o<----o---->o  \n" );
    printf( "     |   - | -   |  Construccion de Maxwell isotérmica en dominio bidimensional\n" );
    printf( "     | -   |   - |  \n" );
    printf( "     o-----o-----o  \n\n" );


    // Argumentos:
    //
    // - argv[1] = Pasos de tiempo
    // - argv[2] = Intervalo de escritura
    // - argv[3] = xgrid

    
    /* int xgrid = atoi( argv[3] ); */


    /* // Pasos de tiempo */
    
    /* uint timeSteps = atoi( argv[1] ); */

    /* uint wrtInterval = atoi( argv[2] ); */

    /* uint nwrite = (uint)(timeSteps/wrtInterval + 1); */

    /* uint* timeList = (uint*)malloc( nwrite * sizeof(uint) ); */
    
    /* for(int i = 0; i < nwrite; i++) */
    /*     timeList[i] = i*wrtInterval;   */
            
    /* cuscalar delta_t = 1.0; */
    


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



    /* // Inicializacion de tiempo */

    /* timeInfo Time; */

    /* startTime(&Time); */


    

    /* // Parametros del modelo */

    /* cuscalar G = -1.0; */

    /* cuscalar c = 1.0; */

    /* cuscalar sigma = 0.125; */
    

    
    /* // Constantes de EOS */

    /* cuscalar a = 0.5; */

    /* cuscalar b = 4; */

    
    
    /* // Gravedad */

    /* scalar g[3] = {0,0,0}; */

    

    /* // Lectura de malla */

    /* basicMesh mesh = readBasicMesh(); */

    /* cudaBasicMesh cmesh; */

    /* hostToDeviceMesh( &cmesh, &mesh ); */
    






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

    /* cuscalar* rho = (cuscalar*)malloc( mesh.nPoints * sizeof(cuscalar) ); //Density */

    /* cuscalar* U = (cuscalar*)malloc( 3 * mesh.nPoints * sizeof(cuscalar) ); // Velocity macroscopic */

    /* cuscalar* Temp = (cuscalar*)malloc( mesh.nPoints * sizeof(cuscalar) ); // Temperature */

    /* cuscalar* fint = (cuscalar*)malloc( mesh.nPoints * 3 * sizeof(cuscalar) ); // Interaction force */

    /* cuscalar* f = (cuscalar*)malloc( mesh.nPoints * 3 * sizeof(cuscalar) ); // Total force ( volumetric add interaction ) */

       
    /* // Inicializacion de f */

    /* for( uint i = 0 ; i < fsize ; i++ ) */
    /*     field[i] = 0.0; */



    /* // Inicializacion de densidad */

    /* for( uint i = 0 ; i < mesh.nPoints ; i++ ) { */

    /* 	/\* rho[i] = (1.0 / 12.0) + (rand() % (3)-1)*0.01*1.0/12.0; *\/ */

    /* 	if( mesh.points[i][1] < 3 ) { */

    /* 	    rho[i] = 0.07; */

    /* 	} */

    /* 	else { */

    /* 	    rho[i] = 0.09; */

    /* 	} */


    /* } */
   



    /* // Inicializacion de velocidad */
    
    /* for( uint i = 0 ; i < mesh.nPoints ; i++ ){ */
	
    /* 	for( uint j = 0 ; j < 3 ; j++ ) { */
	    
    /* 	    U[i*3+j] = 0; */

    /* 	} */

    /* } */


    /* // Inicializacion de Temperatura */

    /* for( uint i = 0 ; i < mesh.nPoints ; i++ ) */
    /* 	Temp[i] = 0.9 / 27.0; */
 



    /* // Inicializacion de fuerzas */

    /* fuerzaFuerzaint(fint, rho, Temp , &mesh, G, c, mesh.lattice.cs2, a, b); */

    /* fuerzaFuerzatotal(f, fint, rho, g, &mesh); */


    /* // Asignacion de distribucion de equilibrio */
    
    /* momentoFeq( &mesh, field, rho, U); */


    
    
    /* // Alocacion de memoria en el device y copia */

    /* cuscalar* deviceField; */

    /* cudaMalloc( (void**)&deviceField, fsize*sizeof(cuscalar) ); */

    /* cudaMemcpy( deviceField, field, fsize*sizeof(cuscalar), cudaMemcpyHostToDevice ); */


    /* cuscalar* deviceRho; */

    /* cudaMalloc( (void**)&deviceRho, mesh.nPoints*sizeof(cuscalar) ); */

    /* cudaMemcpy( deviceRho, rho, mesh.nPoints*sizeof(cuscalar), cudaMemcpyHostToDevice ); */


    /* cuscalar* deviceU; */

    /* cudaMalloc( (void**)&deviceU, 3*mesh.nPoints*sizeof(cuscalar) ); */

    /* cudaMemcpy( deviceU, U, 3*mesh.nPoints*sizeof(cuscalar), cudaMemcpyHostToDevice ); */


    /* cuscalar* deviceT; */

    /* cudaMalloc( (void**)&deviceT, mesh.nPoints*sizeof(cuscalar) ); */

    /* cudaMemcpy( deviceT, Temp, mesh.nPoints*sizeof(cuscalar), cudaMemcpyHostToDevice ); */


    /* cuscalar* deviceFint; */

    /* cudaMalloc( (void**)&deviceFint, 3*mesh.nPoints*sizeof(cuscalar) ); */

    /* cudaMemcpy( deviceFint, fint, 3*mesh.nPoints*sizeof(cuscalar), cudaMemcpyHostToDevice ); */


    /* cuscalar* deviceF; */

    /* cudaMalloc( (void**)&deviceF, 3*mesh.nPoints*sizeof(cuscalar) ); */

    /* cudaMemcpy( deviceF, f, 3*mesh.nPoints*sizeof(cuscalar), cudaMemcpyHostToDevice ); */




    /* // Factores de relajacion para colision */

    /* momentoModelCoeffs relax; */

    /* relax.Tau[0] = 1.0; */
    /* relax.Tau[1] = 0.8; */
    /* relax.Tau[2] = 1.1; */
    /* relax.Tau[3] = 1.0; */
    /* relax.Tau[4] = 1.1; */
    /* relax.Tau[5] = 1.0; */
    /* relax.Tau[6] = 1.1; */
    /* relax.Tau[7] = 0.8; */
    /* relax.Tau[8] = 0.8; */

        
    /* cuscalar* deviceTau; */

    /* cudaMalloc( (void**)&deviceTau, 9*sizeof(cuscalar) ); */

    /* cudaMemcpy( deviceTau, relax.Tau, 9*sizeof(cuscalar), cudaMemcpyHostToDevice ); */




    /* // Antes de comenzar la simulacion, escritura de los campos iniciales */

    /* char scfields[2][100] = {"rho", "T"}; */

    /* char vfields[1][100] = {"U"}; */

    /* updateCaseFile(scfields, 2, vfields, 1, timeList, nwrite); */
    

    /* writeMeshToEnsight( &mesh ); */

    /* writeScalarToEnsight("rho", rho, &mesh, 0); */

    /* writeScalarToEnsight("T", Temp, &mesh, 0); */

    /* writeVectorToEnsight("U", U, &mesh, 0); */

    
    

    /* // Ejecucion LB */

    /* for( uint ts = 1 ; ts < (timeSteps+1) ; ts++ ) { */


    /* 	// Colision */

    /* 	cudaMomentoCollision<<<ceil(mesh.nPoints/xgrid)+1,xgrid>>>( deviceField, deviceRho, deviceU, deviceF, deviceFint, deviceT, */
    /* 								    deviceTau, cmesh.lattice.M, cmesh.lattice.invM, cmesh.nPoints, */
    /* 								    cmesh.Q, delta_t, a, b, c, mesh.lattice.cs2, G, sigma); cudaDeviceSynchronize(); */


    /* 	// Streaming */

	

	
    /* 	// Actualizacion de densidad macroscopica */
	
    /* 	cudaMomentoDensity<<<ceil(mesh.nPoints/xgrid)+1,xgrid>>>( deviceField, deviceRho, cmesh.nPoints, cmesh.Q);  cudaDeviceSynchronize(); */



    /* 	// Actualizacion de fuerzas */

    /* 	cudaFuerzaFuerzaint<<<ceil(mesh.nPoints/xgrid)+1,xgrid>>>( deviceFint, deviceRho, deviceT, cmesh.nPoints, */
    /* 								   cmesh.Q,  cmesh.lattice.vel, cmesh.nb, G, c, mesh.lattice.cs2, a, b);  cudaDeviceSynchronize(); */

    /* 	cudaFuerzaFuerzatotal<<<ceil(mesh.nPoints/xgrid)+1,xgrid>>>( deviceF, deviceFint, deviceRho, g, cmesh.nPoints);  cudaDeviceSynchronize(); */



    /* 	// Actualizacion de velocidad macroscopica */

    /* 	cudaMomentoVelocity<<<ceil(mesh.nPoints/xgrid)+1,xgrid>>>(deviceField, deviceRho, deviceU, cmesh.lattice.vel, */
    /* 								  cmesh.nPoints, cmesh.Q, delta_t );  cudaDeviceSynchronize(); */
	
	


    /* 	// Escritura de campos */
	
    /* 	for( uint wt = 0 ; wt < nwrite ; wt++ ) { */

    /* 	    if( timeList[wt] == ts ) { */


    /* 		// Copia de vuelta al host */

    /* 		cudaMemcpy( rho, deviceRho, mesh.nPoints*sizeof(cuscalar), cudaMemcpyDeviceToHost ); */

    /* 		cudaMemcpy( Temp, deviceT, mesh.nPoints*sizeof(cuscalar), cudaMemcpyDeviceToHost ); */

    /* 		cudaMemcpy( U, deviceU, 3*mesh.nPoints*sizeof(cuscalar), cudaMemcpyDeviceToHost ); */
		

		
    /* 	    	scalar elap = elapsedTime(&Time); */

    /* 	    	printf( " Time = %d\n", ts ); */
		
    /* 	    	printf( " Elapsed time = %.4f segundos\n\n", elap ); */
		

    /* 	    	writeScalarToEnsight("rho", rho, &mesh, wt); */

    /* 	    	writeScalarToEnsight("T", Temp, &mesh, wt); */

    /* 	    	writeVectorToEnsight("U", U, &mesh, wt); */

    /* 	    } */

    /* 	} */

	
	
    /* } */
    

   

    
    /* // Limpieza de memoria host */

    /* freeBasicMesh( &mesh ); */

    /* free( field ); */

    /* free( rho ); */

    /* free( U ); */

    /* free( Temp ); */

    /* free( f ); */

    /* free( fint ); */

    
    /* // Limpieza de memoria device */

    /* cudaFree( deviceField ); */

    /* cudaFree( deviceRho ); */

    /* cudaFree( deviceU ); */

    /* cudaFree( deviceT ); */

    /* cudaFree( deviceFint ); */

    /* cudaFree( deviceF ); */

    /* cudaFree( deviceTau); */

    

   
    return 0;

}
