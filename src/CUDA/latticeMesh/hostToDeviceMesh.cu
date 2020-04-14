#include <hostToDeviceMesh.h>


__host__ void hostToDeviceMesh(cudaBasicMesh* cmesh, basicMesh* hmesh) {


    /**************************************/
    /*              Points                */
    /**************************************/
    

    // First create one-dimensional array

    int* hostPoints = (int*)malloc( hmesh->nPoints * 3 * sizeof(int) );

    for( uint i = 0 ; i < hmesh->nPoints ; i++ ) {

	for( uint j = 0 ; j < 3 ; j++ ) {

	    hostPoints[ 3*i + j ] = hmesh->points[i][j];

	}

    }


    // Copy to device
    
    cudaMalloc( (void**)&cmesh->points, hmesh->nPoints*3*sizeof(int) );

    cudaMemcpy( cmesh->points, hostPoints, hmesh->nPoints*3*sizeof(int), cudaMemcpyHostToDevice );

    free(hostPoints);






    /**************************************/
    /*            Neighbours              */
    /**************************************/


    // First create one-dimensional array

    int* hostNb = (int*)malloc( hmesh->nPoints * hmesh->Q * sizeof(int) );

    for( uint i = 0 ; i < hmesh->nPoints ; i++ ) {

	for( uint j = 0 ; j < hmesh->Q ; j++ ) {

	    hostNb[ hmesh->Q*i + j ] = hmesh->nb[i][j];

	}

    }


    // Copy to device
    
    cudaMalloc( (void**)&cmesh->nb, hmesh->nPoints*hmesh->Q*sizeof(int) );

    cudaMemcpy( cmesh->nb, hostNb, hmesh->nPoints*hmesh->Q*sizeof(int), cudaMemcpyHostToDevice );

    free(hostNb);






    /**************************************/
    /*        Informacion de grilla       */
    /**************************************/    

    cmesh->lattice.model = hmesh->lattice.model;

    cmesh->lattice.d = hmesh->lattice.d;

    cmesh->lattice.q = hmesh->lattice.q;



    // Velocidades de grilla
    
    cudaMalloc( (void**)&cmesh->lattice.vel, 3*hmesh->Q*sizeof(int) );

    cudaMemcpy( cmesh->lattice.vel, hmesh->lattice.vel, 3*hmesh->Q*sizeof(int), cudaMemcpyHostToDevice );
    

    
    // Indices inversos
    
    cudaMalloc( (void**)&cmesh->lattice.reverse, hmesh->Q*sizeof(int) );

    cudaMemcpy( cmesh->lattice.reverse, hmesh->lattice.reverse, hmesh->Q*sizeof(int), cudaMemcpyHostToDevice );


    
    // Matriz de transformacion MRT
    
    cudaMalloc( (void**)&cmesh->lattice.M, hmesh->Q*hmesh->Q*sizeof(int) );

    cudaMemcpy( cmesh->lattice.M, hmesh->lattice.M, hmesh->Q*hmesh->Q*sizeof(int), cudaMemcpyHostToDevice );


    
    // Inversa de matriz de transformacion MRT
    
    cudaMalloc( (void**)&cmesh->lattice.invM, hmesh->Q*hmesh->Q*sizeof(int) );

    cudaMemcpy( cmesh->lattice.invM, hmesh->lattice.invM, hmesh->Q*hmesh->Q*sizeof(int), cudaMemcpyHostToDevice );        
    
    


    /**************************************/
    /*               Other                */
    /**************************************/    

    cmesh->nPoints = hmesh->nPoints;
    
    cmesh->Q = hmesh->Q;

    cmesh->D = hmesh->D;




    /**************************************/
    /*              Fronteras             */
    /**************************************/


    // Cantidad de fronteras
    
    cmesh->bd.nbd = hmesh->bd.nbd;


    // Numero de elementos por frontera

    cudaMalloc( (void**)&cmesh->bd.nbdelem, hmesh->bd.nbd*sizeof(uint) );

    cudaMemcpy( cmesh->bd.nbdelem, hmesh->bd.nbdelem, hmesh->bd.nbd*sizeof(uint), cudaMemcpyHostToDevice );


    
    // Indice de nodos para cada frontera

    {

	// Cantidad maxima de elementos por frontera
	
	uint count = 0;

	for(uint i = 0 ; i < hmesh->bd.nbd ; i++) {

	    if( hmesh->bd.nbdelem[i] > count )	    
		count = hmesh->bd.nbdelem[i];

	}

	cmesh->bd.maxCount = count;

	hmesh->bd.maxCount = count;


	// Primero arreglo unidimensional

	int* hostBdPoints = (int*)malloc( count * hmesh->bd.nbd * sizeof(int) );

	for( uint i = 0 ; i < hmesh->bd.nbd ; i++ ) {

	    for( uint j = 0 ; j < count ; j++ ) {

		if( j < hmesh->bd.nbdelem[i] ) {

		    hostBdPoints[i*count + j] = hmesh->bd.bdPoints[i][j];

		}

		else {

		    hostBdPoints[i*count + j] = -1;

		}
				

	    }

	}
	

	cudaMalloc( (void**)&cmesh->bd.bdPoints, count * hmesh->bd.nbd * sizeof(int) );

	cudaMemcpy( cmesh->bd.bdPoints, hostBdPoints, count * hmesh->bd.nbd * sizeof(int), cudaMemcpyHostToDevice );
	
    }
    
    

    
}
