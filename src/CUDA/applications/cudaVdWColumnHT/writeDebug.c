#include "writeDebug.h"

#include <stdio.h>

#include <stdlib.h>


void writeDebug( scalar* f, scalar* g, scalar* rho, scalar* T, scalar* U, scalar* heat, uint np, uint Q ) {

    
    // Escritura auxiliar de f

    FILE* outfile;

    outfile = fopen("faux","w");
	    
    for (uint i = 0; i < np; i++){


	for (uint j = 0; j < Q; j++)
	    fprintf(outfile,"%.7f ",f[i*Q+j]);
	    	
	fprintf(outfile,"\n");

    }

    fclose(outfile);



    // Escritura auxiliar de g

    outfile = fopen("gaux","w");
	    
    for (uint i = 0; i < np; i++){


	for (uint j = 0; j < Q; j++)
	    fprintf(outfile,"%.7f ",g[i*Q+j]);
	    	
	fprintf(outfile,"\n");

    }

    fclose(outfile);

    
    
    
    // Escritura auxiliar de rho

    outfile = fopen("rhoaux","w");
	    
    for (uint i = 0; i < np; i++)
	fprintf(outfile,"%.7f\n",rho[i]);

    fclose(outfile);


 
    // Escritura auxiliar de T

    outfile = fopen("Taux","w");
	    
    for (uint i = 0; i < np; i++)
	fprintf(outfile,"%.7f\n",T[i]);

    fclose(outfile);   
    


    // Escritura auxiliar de U

    outfile = fopen("Uaux","w");
	    
    for (uint i = 0; i < np; i++){

	for (uint j = 0; j < 3; j++)
	    fprintf(outfile,"%.7f ",U[i*3+j]);
		
	fprintf(outfile,"\n");

    }

    fclose(outfile);


    
    // Escritura auxiliar de heat

    outfile = fopen("heataux","w");
	    
    for (uint i = 0; i < np; i++)
	fprintf(outfile,"%.6f\n",heat[i]);

    fclose(outfile);       

    
}
