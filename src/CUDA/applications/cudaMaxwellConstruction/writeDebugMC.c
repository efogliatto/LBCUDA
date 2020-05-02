#include "writeDebugMC.h"

#include <stdio.h>

#include <stdlib.h>


void writeDebugMC( scalar* f, scalar* rho, scalar* Fint, scalar* Ftot, scalar* U, uint np, uint Q ) {

    
    // Escritura auxiliar de field

    FILE* outfile;

    outfile = fopen("fieldaux","w");
	    
    for (uint i = 0; i < np; i++){


        for (uint j = 0; j < Q; j++)
            fprintf(outfile,"%.7f ",f[i*Q+j]);
                
        fprintf(outfile,"\n");

    }

    fclose(outfile);



    // Escritura auxiliar de rho

    outfile = fopen("rhoaux","w");
	    
    for (uint i = 0; i < np; i++)
	    fprintf(outfile,"%.7f\n",rho[i]);

    fclose(outfile);


    // Escritura auxiliar de Fint

    outfile = fopen("Fintaux","w");
	    
    for (uint i = 0; i < np; i++){

        for (uint j = 0; j < 3; j++)
            fprintf(outfile,"%.7f ",Fint[i*3+j]);
            
        fprintf(outfile,"\n");

    }

    fclose(outfile);

    // Escritura auxiliar de Ftotal

    outfile = fopen("Ftotalaux","w");
	    
    for (uint i = 0; i < np; i++){

        for (uint j = 0; j < 3; j++)
            fprintf(outfile,"%.7f ",Ftot[i*3+j]);
            
        fprintf(outfile,"\n");

    }

    fclose(outfile);


    // Escritura auxiliar de U

    outfile = fopen("Uaux","w");
	    
    for (uint i = 0; i < np; i++){

        for (uint j = 0; j < 3; j++)
            fprintf(outfile,"%.7f ",U[i*3+j]);
            
        fprintf(outfile,"\n");

    }

    fclose(outfile);

    
}
