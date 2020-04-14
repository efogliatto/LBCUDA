#include <cudaScalarGradient.h>

extern "C" __device__ void cudaScalarGradient( cuscalar g[3], cuscalar* field, int* nb, uint id, uint Q ) {

    
    // Inicializacion de gradiente

    for( uint j = 0 ; j < 3 ; j++ )
	g[j] = 0;
   

    // Vecinos
    int a;
    int b;


    
    // X - derivative

    a = nb[id*Q+3];
    b = nb[id*Q+1];
    
    if(  (a != -1)  &&  (b != -1)  ) {
    
	g[0] = 0.5 * (field[a] - field[b]);

    }

    else {

	if(  (a == -1)  &&  (b != -1)  ) {

	    if(nb[b*Q+1] != -1) {

		g[0] = 0.5*(-3*field[id] + 4.0*field[b] - field[nb[b*Q+1]] );

	    }

	    else{		
    
		g[0] = (field[id] - field[b]);

	    }

	}

	else {

	    if(  (a != -1)  &&  (b == -1)  ) {

		if(nb[a*Q+3] != -1) {

		    g[0] = 0.5*(-3*field[id] + 4.0*field[a] - field[nb[a*Q+3]] );

		}

		else{		    
    
		    g[0] = (field[a] - field[id]);

		}

	    }

	    else {

		g[0] = 0;

	    }

	}

    }




    // Y - derivative

    a = nb[id*Q+4];
    b = nb[id*Q+2];
    
    if(  (a != -1)  &&  (b != -1)  ) {
    
	g[1] = 0.5 * (field[a] - field[b]);

    }

    else {

	if(  (a == -1)  &&  (b != -1)  ) {

	    if(nb[b*Q+2] != -1) {

		g[1] = 0.5*(-3*field[id] + 4.0*field[b] - field[nb[b*Q+2]] );

	    }

	    else {		
    
		g[1] = (field[id] - field[b]);

	    }

	}

	else {

	    if(  (a != -1)  &&  (b == -1)  ) {

		if(nb[a*Q+4] != -1) {

		    g[1] = 0.5*(-3*field[id] + 4.0*field[a] - field[nb[a*Q+4]] );

		}

		else {		    
    
		    g[1] = (field[a] - field[id]);

		}

	    }

	    else {

		g[1] = 0;

	    }

	}

    }
    

}
