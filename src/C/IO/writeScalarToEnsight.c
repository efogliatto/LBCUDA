#include <writeScalarToEnsight.h>

#include <stdio.h>

#include <stdlib.h>

#include <string.h>


void writeScalarToEnsight( char* fname, scalar* field, basicMesh* mesh, uint fcount ) {


    // Write field
    
    FILE *outFile;

    char fileName[100];

    sprintf(fileName, "lattice.%s_%d", fname, fcount);
    

    // Header	
	
    outFile = fopen(fileName, "wb");

    /* testFile(outFile, fileName); */

    char* msg = (char*)malloc( 80*sizeof(char) );

    memset(msg,'\0', 80);	

    sprintf(msg, "%s", fname);

    fwrite( msg, sizeof(char), 80, outFile );	  

    fclose(outFile);


    

    // Part description

    outFile = fopen(fileName, "ab");

    /* testFile(outFile, fileName); */

    

    memset(msg,'\0', 80);	

    sprintf(msg, "part");
	
    fwrite( msg, sizeof(char), 80, outFile );


	
    uint pid = 1;

    fwrite( &pid, sizeof(int), 1, outFile );



    memset(msg,'\0', 80);	

    sprintf(msg, "coordinates");
	
    fwrite( msg, sizeof(char), 80, outFile );
	


    
    uint i;

    float value;
    
    for( i = 0 ; i < mesh->nPoints ; i++ ) {

	value = (float)field[i];
	    
	fwrite( &value, sizeof(float), 1, outFile );
	
    }


    fclose(outFile);

    free(msg);

    

}
