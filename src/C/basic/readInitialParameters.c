#include <stdio.h>
#include <stdlib.h>
#include <readInitialParameters.h>


void readInitialParameters( scalar *G, scalar *c,scalar *sigma, scalar *a, scalar *b, scalar *g, scalar *Tr, scalar *Tc, scalar *Rhoc){

    scalar parameter;
    scalar par[11];

    FILE *handle;
    int n = 0;

    if ( ( handle = fopen ("InitialParameters.txt", "r")) == NULL){
        printf ("could not open file\n");
        return ; // or exit(1);
    }
    
    while ( ( fscanf(handle, "%lf", &parameter) ) == 1){
        par[n] = parameter;
        n++;
    }

    *G=par[0];
    *c=par[1];
    *sigma=par[2];
    *a=par[3];
    *b=par[4];
    g[0]=par[5];
    g[1]=par[6];
    g[2]=par[7];
    *Tr=par[8];
    *Tc=par[9];
    *Rhoc=par[10];

   fclose ( handle);
}
