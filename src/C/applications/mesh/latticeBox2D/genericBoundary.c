#include <stdio.h>
#include <stdlib.h>
#include <basicMesh.h>


void genericBoundary( basicMesh* mesh, uint nx, uint ny ) {

    mesh->bd.nbd = 4;
    
    mesh->bd.nbdelem = (uint*)malloc( 4 * sizeof(uint) );
    mesh->bd.bdPoints = (uint**)malloc( 4 * sizeof(uint*) );

    mesh->bd.nbdelem[0] = ny;
    mesh->bd.nbdelem[1] = ny;
    mesh->bd.nbdelem[2] = (nx-2);
    mesh->bd.nbdelem[3] = (nx-2);

    mesh->bd.bdPoints[0] = (uint*)malloc( mesh->bd.nbdelem[0] * sizeof(uint) );
    mesh->bd.bdPoints[1] = (uint*)malloc( mesh->bd.nbdelem[1] * sizeof(uint) );
    mesh->bd.bdPoints[2] = (uint*)malloc( mesh->bd.nbdelem[2] * sizeof(uint) );
    mesh->bd.bdPoints[3] = (uint*)malloc( mesh->bd.nbdelem[3] * sizeof(uint) );   


    
    int j;


    // Move over X-boundary points
    for( j = 0 ; j < ny ; j++ ) {

    	mesh->bd.bdPoints[0][j] = j*nx;
	
    	mesh->bd.bdPoints[1][j] = (nx-1) + j*nx;

    }
    
    
    // Move over Y-boundary points
    for( j = 1 ; j < (nx-1) ; j++ ) {

    	mesh->bd.bdPoints[2][j-1] = j;
	
    	mesh->bd.bdPoints[3][j-1] = j + (nx-1)*ny;

    }


    
}
