/*

  maxwellConstruction

  Problema de construcción de Maxwell

 */



    
#include <latticeMesh.h>

#include <basic.h>

#include <timeInfo.h>

#include <momentoFunciondist.h>   

#include <fuerza.h>

#include <streaming.h>

#include <IO.h>


#include <stdlib.h>

#include <stdio.h>

#include <math.h>

#include "writeDebug.h"



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
    // - argv[1] = Pasos de tiempo
    // - argv[2] = Intervalo de escritura

    
  
    // Parámetros a Inicializar
    
        // Parametros del modelo

        scalar G ;

        scalar c ;

        scalar sigma ;
                       
        // Constantes de EOS

        scalar a ;

        scalar b ;
        
        // Gravedad

        scalar g[3] ;

        // Temperatura de referencia

        scalar Tr;

        // Temperatura critica

        scalar Tc ;

        // Densidad critica

        scalar Rhoc ;
       

    readInitialParameters( &G, &c, &sigma, &a, &b, g, &Tr, &Tc, &Rhoc);     // Archivo de lectura InitialParameters.txt su forma esta en el .h

    /*        
    printf("\t G = %f\n",G);
    printf("\t c = %f\n",c);
    printf("\t sigma = %f\n",sigma);
    printf("\t a = %f\n",a);
    printf("\t b = %f\n",b);
    printf("\t g = (%f\t, %f\t, %f)\n",g[0],g[1],g[2]);    
    printf("\t Tr = %f\n",Tr);
    printf("\t Tc = %f\n",Tc);
    printf("\t Rhoc = %f\n\n",Rhoc);
    */

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

    scalar* streamingField = (scalar*)malloc( fsize * sizeof(scalar) );


    
    // Alocacion de arreglo de salida

    scalar* rho = (scalar*)malloc( mesh.nPoints * sizeof(scalar) ); //Density

    scalar* U = (scalar*)malloc( 3 * mesh.nPoints * sizeof(scalar) ); // Velocity macroscopic    

    scalar* Temp = (scalar*)malloc( mesh.nPoints * sizeof(scalar) ); // Temperature

    scalar* fint = (scalar*)malloc( mesh.nPoints * 3 * sizeof(scalar) ); // Interaction force

    scalar* f = (scalar*)malloc( mesh.nPoints * 3 * sizeof(scalar) ); // Total force ( volumetric add interaction ) 


    
    // Inicializacion de f

    for( uint i = 0 ; i < fsize ; i++ )
        field[i] = 0.0;



    // Inicializacion de densidad

    for( uint i = 0 ; i < mesh.nPoints ; i++ ) {

        rho[i] = Rhoc + (rand() % (3)-1)* 0.01 * Rhoc;

        /* if( mesh.points[i][1] < 3 ) { 

            rho[i] = 0.07; 

        } 

        else { 

            rho[i] = 0.09; 

        } */


    }
   



    // Inicializacion de velocidad
    
    for( uint i = 0 ; i < mesh.nPoints ; i++ ){
	
	    for( uint j = 0 ; j < 3 ; j++ ) {
	    
	        U[i*3+j] = 0;

	    }

    }


    // Inicializacion de Temperatura

    for( uint i = 0 ; i < mesh.nPoints ; i++ )
    	Temp[i] = Tr * Tc;
 



    // Inicializacion de fuerzas

    fuerzaFuerzaint(fint, rho, Temp , &mesh, G, c, mesh.lattice.cs2, a, b);

    fuerzaFuerzatotal(f, fint, rho, g, &mesh);     



    
    // Asignacion de distribucion de equilibrio
    
    momentoFeq( &mesh, field, rho, U);   

    
    
    // Factores de relajacion para colision

    momentoModelCoeffs relax;

    relax.Tau[0] = 1.0;
    relax.Tau[1] = 0.8;
    relax.Tau[2] = 1.1;
    relax.Tau[3] = 1.0;
    relax.Tau[4] = 1.1;
    relax.Tau[5] = 1.0;
    relax.Tau[6] = 1.1;
    relax.Tau[7] = 0.8;
    relax.Tau[8] = 0.8;
    

    
    // Pasos de tiempo
    
    uint timeSteps = atoi( argv[1] );

    uint wrtInterval = atoi( argv[2] );

    uint nwrite = (uint)(timeSteps/wrtInterval + 1);

    uint* timeList = (uint*)malloc( nwrite * sizeof(uint) );
    
    for(int i = 0; i < nwrite; i++)
        timeList[i] = i*wrtInterval;

   
            
    scalar delta_t = 1.0;



    // Antes de comenzar la simulacion, escritura de los campos iniciales

    char scfields[2][100] = {"rho", "T"};

    char vfields[1][100] = {"U"};

    updateCaseFile(scfields, 2, vfields, 1, timeList, nwrite);
    

    writeMeshToEnsight( &mesh );

    writeScalarToEnsight("rho", rho, &mesh, 0);

    writeScalarToEnsight("T", Temp, &mesh, 0);

    writeVectorToEnsight("U", U, &mesh, 0);
   
	

    // Inicializacion toma de tiempo

    timeInfo Time;

    startTime(&Time);


      
    for( uint k = 1 ; k < (timeSteps+1) ; k++ ) { 


	    // Colision
	
        momentoCollision( &mesh, &relax, field, rho, U, f, fint, Temp, delta_t, a, b, c, mesh.lattice.cs2, G, sigma);


	
        // Streaming

        lbstreaming(field, streamingField, &mesh);


	
	    // Actualizacion de densidad macroscopica

        momentoDensity( rho, field, &mesh);



    	// Actualizacion de fuerzas

	    fuerzaFuerzaint(fint, rho, Temp , &mesh, G, c, mesh.lattice.cs2, a, b);

	    fuerzaFuerzatotal(f, fint, rho, g, &mesh);
	
	

	    // Actualizacion de velocidad macroscopica
	
        momentoVelocity( rho,  U, field, &mesh, delta_t, f);




        // Escritura de campos
        
        for( uint wt = 0 ; wt < nwrite ; wt++ ) {

            if( timeList[wt] == k ) {


                scalar elap = elapsedTime(&Time);

                printf( " Tiempo = %d\n", k );
                
                printf( " Tiempo de ejecución = %.4f segundos\n\n", elap );
                

                writeScalarToEnsight("rho", rho, &mesh, wt);

                writeScalarToEnsight("T", Temp, &mesh, wt);

                writeVectorToEnsight("U", U, &mesh, wt);

                
            }

	    }

    }

    // Finalizacion toma de tiempo

    scalar elap = elapsedTime(&Time);


    // writeDebug(field, rho, Temp, U, mesh.nPoints, mesh.Q);
    
   
    // Limpieza de memoria 

    freeBasicMesh( &mesh );

    free( field );

    free( streamingField );

    free( rho );

    free( U ); 

    free( Temp );

    free( f );   

    free( fint );
    



    printf( "\n Fin. Tiempo total = %.4f segundos\n\n", elap );

    
    return 0;

}
