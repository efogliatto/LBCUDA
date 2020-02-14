#include <MRT_invMatrix.h>

#include <D2Q9.h>

#include <stdlib.h>



scalar* MRT_invMatrix( DdQq model ) {

    scalar* M = NULL;

    
    switch( model ) {

	
    case D2Q9:

	M = D2Q9_MRT_invMatrix();

	break;

	
    default:

	M = NULL;

	break;

    }

    

    return M;


}
