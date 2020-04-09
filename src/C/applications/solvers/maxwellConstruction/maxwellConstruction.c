/*

  maxwellConstruction

  Problema de construcción de Maxwell

 */



    
#include <latticeMesh.h>

#include <basic.h>

#include <timeInfo.h>

#include <momentoFunciondist.h>   

#include <fuerza.h>

//#include <energy.h>

#include <streaming.h>

#include <IO.h>


#include <stdlib.h>

#include <stdio.h>

#include <math.h>





int main(int argc, char** argv) {


    
    
    printf( "                    \n" );
    printf( "     o-----o-----o  \n" );
    printf( "     | -   |   - |  \n" );
    printf( "     |   - | -   |                maxwellConstruction\n" );
    printf( "     o<----o---->o  \n" );
    printf( "     |   - | -   |  Problema de Construcción de Maxwell en CPU \n" );
    printf( "     | -   |   - |  \n" );
    printf( "     o-----o-----o  \n\n" );


    // Argumentos:
    //
    // - argv[1] = numero de iteraciones
    

    uint nit  = atoi( argv[1] );

    
    


       
    // Parametros del modelo D2Q9

    int a = 0.5;

    int b = 4;

    scalar G = -1.0; 

    scalar c = 1.0; 

    scalar cs_2 = ( 1.0/3.0 ); 

    scalar sigma = 0.125;

    // Aceleracion del problema

    scalar g[3] = {0,0,0};

    

    // Lectura de malla

    basicMesh mesh = readBasicMesh();

    // Inicialización de la información del tiempo
    
    //timeInfo* infoT;

    
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

    scalar* streamingField = (scalar*)malloc( fsize * sizeof(scalar) );

    
    // Alocacion de arreglo de salida

    scalar* rho = (scalar*)malloc( mesh.nPoints * sizeof(scalar) ); //Density

    scalar* U = (scalar*)malloc( 3 * mesh.nPoints * sizeof(scalar) ); // Velocity macroscopic    

    scalar* Temp = (scalar*)malloc( mesh.nPoints * sizeof(scalar) ); // Temperature

    scalar* fint = (scalar*)malloc( mesh.nPoints * 3 * sizeof(scalar) ); // Interaction force

    scalar* f = (scalar*)malloc( mesh.nPoints * 3 * sizeof(scalar) ); // Total force ( volumetric add interaction ) 

       
    // Inicializacion (puede ser otra)

    for( uint i = 0 ; i < fsize ; i++ ){
        field[i] = 0.0;
    }

    /*for( uint i = 0 ; i < mesh.nPoints ; i++ ){
        rho[i] = (1.0 / 12.0) + (rand() % (3)-1)*0.01*1.0/12.0;

    }*/

    rho[0] = 0.07;
    rho[1] = 0.07;
    for( uint i = 2 ; i < mesh.nPoints ; i++ ){
        rho[i] = 0.09;
    }

    
    for( uint i = 0 ; i < mesh.nPoints ; i++ ){
	    for( uint j = 0 ; j < 3 ; j++ ){
	        U[i*3+j] = 0;
	    }
    }

    for( uint i = 0 ; i < mesh.nPoints ; i++ ){
    	Temp[i] = 0.9 / 27.0;
    }

    for( uint i = 0 ; i < (3*mesh.nPoints) ; i++ ){
    	fint[i] = 0.0;
    }

    for( uint i = 0 ; i < (3*mesh.nPoints) ; i++ ){
    	f[i] = 0.0 ;
    }
        
         
    // Factores de relajacion para colision

    momentoModelCoeffs relax;

    /*for( uint i = 0 ; i < 9 ; i++ ){
        relax.Tau[i] = 1;
    }*/
    relax.Tau[0] = 1.0; //{1.0, 0.8, 1.1, 1.0, 1.1, 1.0, 1.1, 0.8, 0.8};
    relax.Tau[1] = 0.8;
    relax.Tau[2] = 1.1;
    relax.Tau[3] = 1.0;
    relax.Tau[4] = 1.1;
    relax.Tau[5] = 1.0;
    relax.Tau[6] = 1.1;
    relax.Tau[7] = 0.8;
    relax.Tau[8] = 0.8;
    
    // Escritura de lbm.case
    
    int timeStep = 21;

    uint timeList[timeStep];
    
    for (int i = 0; i < timeStep; i++){
        timeList[i] = i*500;
    }
    

            
    scalar delta_t = 1.0;	


    int comp = 0;

    momentoFeq( &mesh, field, rho, U);   // Inicialización de field en el equilibrio        

    	printf("FIELD_EQ\n\n");

    for (uint i = 0; i < mesh.nPoints; i++){

		for (uint j = 0; j < mesh.Q; j++){
			printf("%f \t",field[i*mesh.Q+j]);
		}
		
		printf("\n");

	}
    // Reduccion

    printf(" Colisión en %d iteraciones\n\n", nit);

    timeInfo Time;

    startTime(&Time);

       
    //for( uint k = 0 ; k < timeList[timeStep] ; k++ ) {  //Hará todos los pasos indicados : 500 *20 = 10000
    for( uint k = 0 ; k < 1 ; k++ ) { //Se hará en 1 paso para verificar que de igual que en phoenix
        
        momentoCollision( &mesh, &relax, field, rho, U, f, fint, Temp, delta_t, a, b, c, cs_2, G, sigma);   //Collision

        streamingNbReduction( streamingField, field, &mesh);    //Calculo del valor del streaming punto a punto

        streamingUpdate( field, streamingField, &mesh);         //Realización del streaming
        

        fuerzaFuerzaint(fint, rho, Temp , &mesh, G, c, cs_2, a, b); //Calculo de la fuerza interna

        fuerzaFuerzatotal(f, fint, rho, g, &mesh);  //Calculo de la fuerza externa

        momentoVelocity( rho,  U, field, &mesh, delta_t, f); //Actualización de la velocidad macroscópica

        momentoDensity( rho, field, &mesh);   //Actualización de la densidad macroscópica


        if (k == timeList[comp]){
            
            writeMeshToEnsight( &mesh );

            writeScalarToEnsight("rho", rho, &mesh, comp);

            writeScalarToEnsight("T", Temp, &mesh, comp);

            writeVectorToEnsight("U", U, &mesh, comp);

            comp++;
        }

    	
        printf("FIELD_step_1\n\n");

        for (uint i = 0; i < mesh.nPoints; i++){

		    for (uint j = 0; j < mesh.Q; j++){
			    printf("%f \t",field[i*mesh.Q+j]);
		    }
		
		    printf("\n");

	    }

    }

    //Actualización del caso Maestro

    char scfields[2][100] = {"rho", "T"};

    char vfields[1][100] = {"U"};

    updateCaseFile(scfields, 2, vfields, 1, timeList, timeStep);


    scalar elap = elapsedTime(&Time);
    
    printf( "\n   Colisión finalizada en %f segundos\n", elap );
    printf( "\n   Tiempo promedio de ejecución por iteración: %g segundos\n\n", elap/nit );

    
   
    // Limpieza de memoria 

    freeBasicMesh( &mesh );

    free( field );

    free( streamingField );

    free( rho );

    free( U ); 

    free( Temp );

    free( f );   

    free( fint );
    

    return 0;

}
