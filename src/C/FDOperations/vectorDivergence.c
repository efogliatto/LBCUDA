#include <vectorDivergence.h>

scalar vectorDivergence( scalar* field, basicMesh* mesh, uint id ){
    

    // Constants

    int a, b;

    scalar d = 0;


    	// X - derivative

    	a = mesh->nb[id][3];
	
    	b = mesh->nb[id][1];

	
    	if(  (a != -1)  &&  (b != -1)  ) {
    
    	    d += 0.5 * (field[a*3+0] - field[b*3+0]);

    	}

    	else {

    	    if(  (a == -1)  &&  (b != -1)  ) {
    
    		d += (field[id*3+0] - field[b*3+0]);

    	    }

    	    else {

    		if(  (a != -1)  &&  (b == -1)  ) {
    
    		    d += (field[a*3+0] - field[id*3+0]);

    		}

    	    }

    	}




    	// Y - derivative

    	a = mesh->nb[id][4];
	
    	b = mesh->nb[id][2];

	
    	if(  (a != -1)  &&  (b != -1)  ) {
    
    	    d += 0.5 * (field[a*3+1] - field[b*3+1]);

    	}

    	else {

    	    if(  (a == -1)  &&  (b != -1)  ) {
    
    		d += (field[id*3+1] - field[b*3+1]);

    	    }

    	    else {

    		if(  (a != -1)  &&  (b == -1)  ) {
    
    		    d += (field[a*3+1] - field[id*3+1]);

    		}

    	    }

    	} 


    return d;


}
