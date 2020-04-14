/*

  VdWColumnHT

  Estratificacion de fluido VdW con temperatura no uniforme

 */



    
#include <latticeMesh.h>

#include <basic.h>

#include <timeInfo.h>

#include <momentoFunciondist.h>   

#include <fuerza.h>

#include <energy.h>

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
    printf( "     |   - | -   |                            VdWColumnHT\n" );
    printf( "     o<----o---->o  \n" );
    printf( "     |   - | -   |  Estratificación de fluido Van der Waals con ecuación de enrgía en CPU \n" );
    printf( "     | -   |   - |  \n" );
    printf( "     o-----o-----o  \n\n" );



    // Argumentos:
    //
    // - argv[1] = Pasos de tiempo
    // - argv[2] = Intervalo de escritura

    

    // Inicializacion de tiempo

    timeInfo Time;

    startTime(&Time);



    // Pasos de tiempo
    
    uint timeSteps = atoi( argv[1] );

    uint wrtInterval = atoi( argv[2] );

    uint nwrite = (uint)(timeSteps/wrtInterval + 1);

    uint* timeList = (uint*)malloc( nwrite * sizeof(uint) );
    
    for(int i = 0; i < nwrite; i++)
        timeList[i] = i*wrtInterval;  
            
    scalar delta_t = 1.0;

      
    
       
    // Parametros del modelo

    scalar G = -1.0;

    scalar c = 1.0;

    scalar sigma = 0.125;
    

    
    // Constantes de EOS

    scalar a = 0.5;

    scalar b = 4;

    
    
    // Gravedad

    scalar g[3] = {0,-1.234567e-07,0};

    

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
    
    scalar* field_f = (scalar*)malloc( fsize * sizeof(scalar) );

    scalar* field_g = (scalar*)malloc( fsize * sizeof(scalar) );

    scalar* streamingField = (scalar*)malloc( fsize * sizeof(scalar) );


    
    // Alocacion de arreglo de salida

    scalar* rho = (scalar*)malloc( mesh.nPoints * sizeof(scalar) ); //Density

    scalar* U = (scalar*)malloc( 3 * mesh.nPoints * sizeof(scalar) ); // Velocity macroscopic    

    scalar* Temp = (scalar*)malloc( mesh.nPoints * sizeof(scalar) ); // Temperature

    scalar* fint = (scalar*)malloc( mesh.nPoints * 3 * sizeof(scalar) ); // Interaction force

    scalar* f = (scalar*)malloc( mesh.nPoints * 3 * sizeof(scalar) ); // Total force ( volumetric add interaction )

    scalar* heat = (scalar*)malloc( mesh.nPoints * sizeof(scalar) ); // Fuente de eq. de energia
    


    
    // Inicializacion de f

    for( uint i = 0 ; i < fsize ; i++ )
        field_f[i] = 0.0;

    
    // Inicializacion de g

    for( uint i = 0 ; i < fsize ; i++ )
        field_g[i] = 0.0;    



    // Inicializacion de densidad

    for( uint i = 0 ; i < mesh.nPoints ; i++ ) {

	/* rho[i] = (1.0 / 12.0) + (rand() % (3)-1)*0.01*1.0/12.0; */

	if( mesh.points[i][1] < 3 ) {

	    rho[i] = 0.09;

	}

	else {

	    rho[i] = 0.07;

	}

    }
   


    // Inicializacion de velocidad
    
    for( uint i = 0 ; i < mesh.nPoints ; i++ ){
	
	for( uint j = 0 ; j < 3 ; j++ ) {
	    
	    U[i*3+j] = 0;

	}

    }


    // Inicializacion de Temperatura

    for( uint i = 0 ; i < mesh.nPoints ; i++ )
    	Temp[i] = 0.036667;
 

        
    
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



    // Factores de relajacion para energia

    energyCoeffs energyRelax;
    
    energyRelax.Tau[0] = 1.0;
    energyRelax.Tau[1] = 1.0;
    energyRelax.Tau[2] = 1.0;
    energyRelax.Tau[3] = 0.8;
    energyRelax.Tau[4] = 1.0;
    energyRelax.Tau[5] = 0.8;
    energyRelax.Tau[6] = 1.0;
    energyRelax.Tau[7] = 1.0;
    energyRelax.Tau[8] = 1.0;

    energyRelax.alpha_1 = 1;
    energyRelax.alpha_2 = 1;
    energyRelax.Cv = 1;





    // Inicializacion de fuerzas y fuentes

    fuerzaFuerzaint(fint, rho, Temp , &mesh, G, c, mesh.lattice.cs2, a, b);

    fuerzaFuerzatotal(f, fint, rho, g, &mesh);

    energyS( &mesh, heat, rho, Temp, U, &energyRelax, mesh.lattice.cs2, delta_t, b);


    
    
    // Asignacion de distribucion de equilibrio
    
    momentoFeq( &mesh, field_f, rho, U);

    energyEqDistMomento( &mesh, field_g, Temp, U, &energyRelax );




    // Antes de comenzar la simulacion, escritura de los campos iniciales

    char scfields[2][100] = {"rho", "T"};

    char vfields[1][100] = {"U"};

    updateCaseFile(scfields, 2, vfields, 1, timeList, nwrite);
    

    writeMeshToEnsight( &mesh );

    writeScalarToEnsight("rho", rho, &mesh, 0);

    writeScalarToEnsight("T", Temp, &mesh, 0);

    writeVectorToEnsight("U", U, &mesh, 0);
   
	




      
    for( uint k = 1 ; k < (timeSteps+1) ; k++ ) {



	// Ecuacion de energia

	energyCollision( &mesh, field_g, heat, Temp, U, &energyRelax, delta_t);

	lbstreaming(field_g, streamingField, &mesh);

	fixedTBoundary( &mesh, field_g, Temp, U, "Y1", 0.036667, energyRelax.alpha_1, energyRelax.alpha_2);

	fixedTBoundary( &mesh, field_g, Temp, U, "Y0", 0.033333, energyRelax.alpha_1, energyRelax.alpha_2);	

	energyS( &mesh, heat, rho, Temp, U, &energyRelax, mesh.lattice.cs2, delta_t, b);

	energyTemp( &mesh, Temp, field_g, heat, delta_t );
	
	

	// Ecuaciones hidrodinamicas

        momentoCollision( &mesh, &relax, field_f, rho, U, f, fint, Temp, delta_t, a, b, c, mesh.lattice.cs2, G, sigma);

	lbstreaming(field_f, streamingField, &mesh);

	NEBB( &mesh, field_f, f, "Y0", 2 );

	NEBB( &mesh, field_f, f, "Y1", 3 );

        momentoDensity( rho, field_f, &mesh);

	fuerzaFuerzaint(fint, rho, Temp , &mesh, G, c, mesh.lattice.cs2, a, b);

	fuerzaFuerzatotal(f, fint, rho, g, &mesh);
			
        momentoVelocity( rho,  U, field_f, &mesh, delta_t, f);




	// Escritura de campos
	
	for( uint wt = 0 ; wt < nwrite ; wt++ ) {

	    if( timeList[wt] == k ) {


		scalar elap = elapsedTime(&Time);

		printf( " Tiempo = %d\n", k );
		
		printf( " Tiempo de ejecución = %.4f segundos\n\n", elap );
		

		writeScalarToEnsight("rho", rho, &mesh, wt);

		writeScalarToEnsight("T", Temp, &mesh, wt);

		writeVectorToEnsight("U", U, &mesh, wt);


		writeDebug(field_f, field_g, rho, Temp, U, heat, mesh.nPoints, mesh.Q);

	    }

	}

	

	

    }



    
   
    // Limpieza de memoria 

    freeBasicMesh( &mesh );

    free( field_f );

    free( field_g );    

    free( streamingField );

    free( rho );

    free( U ); 

    free( Temp );

    free( f );   

    free( fint );

    free( heat );
    



    scalar elap = elapsedTime(&Time);
	
    printf( "\n Fin. Tiempo total = %.4f segundos\n\n", elap );

    
    return 0;

}
