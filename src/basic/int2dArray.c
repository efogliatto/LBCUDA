#include <stdio.h>
#include <stdlib.h>
#include <int2dArray.h>

unsigned int int2dArray(int*** M, unsigned int nrow, unsigned int ncol, int df) {

    
    unsigned int status = 1;

    *M = (int**)malloc( nrow * sizeof(int*) );

    unsigned int i,j;

    for( i = 0 ; i < nrow ; i++ ) {

    	M[0][i] = (int*)malloc( ncol * sizeof(int) );

    }

    for( i = 0 ; i < nrow ; i++ ) {

    	for( j = 0 ; j < ncol ; j++ ) {

    	    M[0][i][j] = df;


	    // Check for assignment
	    
	    if( M[0][i][j] != df )
		status = 0;

    	}

    }
    

    return status;

}
