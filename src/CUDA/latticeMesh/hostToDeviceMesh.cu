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

    cudaMemcpy( &cmesh->points, hostPoints, hmesh->nPoints*3*sizeof(int), cudaMemcpyHostToDevice );

    free(hostPoints);






    /**************************************/
    /*            Neighbours              */
    /**************************************/


    // First create one-dimensional array

    int* hostNb = (int*)malloc( hmesh->nPoints * hmesh->Q * sizeof(int) );

    for( uint i = 0 ; i < hmesh->nPoints ; i++ ) {

	for( uint j = 0 ; j < hmesh->Q ; j++ ) {

	    hostNb[ 3*i + j ] = hmesh->nb[i][j];

	}

    }


    // Copy to device
    
    cudaMalloc( (void**)&cmesh->nb, hmesh->nPoints*hmesh->Q*sizeof(int) );

    cudaMemcpy( &cmesh->nb, hostNb, hmesh->nPoints*hmesh->Q*sizeof(int), cudaMemcpyHostToDevice );

    free(hostNb);





    /**************************************/
    /*               Other                */
    /**************************************/    

    cmesh->Q = hmesh->Q;

    cmesh->D = hmesh->D;
    
}
