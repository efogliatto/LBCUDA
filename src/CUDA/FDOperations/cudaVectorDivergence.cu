#include <vectorDivergence.h>

extern "C" __device__ void cudaVectorDivergence( cuscalar* d, cuscalar* field, int* nb, uint id, uint Q ) {
    

    // Constants

    int a, b;

    *d = 0;


    // X - derivative

    a = nb[id*Q+3];
	
    b = nb[id*Q+1];

	
    if(  (a != -1)  &&  (b != -1)  ) {
    
	*d += 0.5 * (field[a*3+0] - field[b*3+0]);

    }

    else {

	if(  (a == -1)  &&  (b != -1)  ) {
    
	    *d += (field[id*3+0] - field[b*3+0]);

	}

	else {

	    if(  (a != -1)  &&  (b == -1)  ) {
    
		*d += (field[a*3+0] - field[id*3+0]);

	    }

	}

    }




    // Y - derivative

    a = nb[id*Q+4];
	
    b = nb[id*Q+2];

	
    if(  (a != -1)  &&  (b != -1)  ) {
    
	*d += 0.5 * (field[a*3+1] - field[b*3+1]);

    }

    else {

	if(  (a == -1)  &&  (b != -1)  ) {
    
	    *d += (field[id*3+1] - field[b*3+1]);

	}

	else {

	    if(  (a != -1)  &&  (b == -1)  ) {
    
		*d += (field[a*3+1] - field[id*3+1]);

	    }

	}

    } 



}
