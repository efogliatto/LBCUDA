#include <stdio.h>
#include <stdlib.h>
#include <latticeCS2.h>

scalar latticeCS2( DdQq model ) {

    scalar vel = 1;

    
    switch( model ) {

	
    case D2Q9:

	vel = 1.0 / 3.0;

	break;

	
    /* case D3Q15: */

    /* 	vel = D3Q15_Vel(); */

    /* 	break; */

	
    default:

	vel = 1;

	break;

    }

    

    return vel;

}
