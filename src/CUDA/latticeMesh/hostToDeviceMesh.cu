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
    
}
