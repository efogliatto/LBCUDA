#include <stdio.h>
#include <stdlib.h>
#include <scalar2dArray.h>


scalar scalar2dArray(scalar*** M, unsigned int nrow, unsigned int ncol, scalar df) {

    
    unsigned int status = 1;

    *M = (scalar**)malloc( nrow * sizeof(scalar*) );

    unsigned int i,j;

    for( i = 0 ; i < nrow ; i++ ) {

    	M[0][i] = (scalar*)malloc( ncol * sizeof(scalar) );

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
