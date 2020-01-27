#include <stdio.h>
#include <stdlib.h>
#include <latticeReverseDir.h>

int* latticeReverseDir( DdQq model ) {

    int* vel = NULL;


    switch( model ) {

	
    case D2Q9:

	vel = D2Q9_Reverse();

	break;

	
    /* case D3Q15: */

    /* 	vel = D3Q15_Reverse(); */

    /* 	break; */

	
    default:

	vel = NULL;

	break;

    }

    

    return vel;

}
