#include <scalarGradient.h>

void scalarGradient( scalar g[3], scalar* field, basicMesh* mesh, uint id ) {

    
    // Inicializacion de gradiente

    for( uint j = 0 ; j < 3 ; j++ )
	g[j] = 0;
   

    // Vecinos
    int a;
    int b;



    
    // X - derivative

    a = mesh->nb[id][3];
    b = mesh->nb[id][1];
    
    if(  (a != -1)  &&  (b != -1)  ) {
    
	g[0] = 0.5 * (field[a] - field[b]);

    }

    else {

	if(  (a == -1)  &&  (b != -1)  ) {

	    if(mesh->nb[b][1] != -1) {

		g[0] = 0.5*(-3*field[id] + 4.0*field[b] - field[mesh->nb[b][1]] );

	    }

	    else{		
    
		g[0] = (field[id] - field[b]);

	    }

	}

	else {

	    if(  (a != -1)  &&  (b == -1)  ) {

		if(mesh->nb[a][3] != -1) {

		    g[0] = 0.5*(-3*field[id] + 4.0*field[a] - field[mesh->nb[a][3]] );

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

    a = mesh->nb[id][4];
    b = mesh->nb[id][2];
    
    if(  (a != -1)  &&  (b != -1)  ) {
    
	g[1] = 0.5 * (field[a] - field[b]);

    }

    else {

	if(  (a == -1)  &&  (b != -1)  ) {

	    if(mesh->nb[b][2] != -1) {

		g[1] = 0.5*(-3*field[id] + 4.0*field[b] - field[mesh->nb[b][2]] );

	    }

	    else {		
    
		g[1] = (field[id] - field[b]);

	    }

	}

	else {

	    if(  (a != -1)  &&  (b == -1)  ) {

		if(mesh->nb[a][4] != -1) {

		    g[1] = 0.5*(-3*field[id] + 4.0*field[a] - field[mesh->nb[a][4]] );

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
