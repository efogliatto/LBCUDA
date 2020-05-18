#include <writeTime.h>

#include <stdio.h>

#include <stdlib.h>

void writeTime( scalar elap) {

    //Escritura del tiempo 
    
    FILE* outfile;

    outfile = fopen("time_exc","w");

    fprintf(outfile,"%.4f\n",elap);

    fclose(outfile);       

}