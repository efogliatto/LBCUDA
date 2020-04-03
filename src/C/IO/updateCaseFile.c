#include <updateCaseFile.h>

#include <string.h>



void updateCaseFile( char scalarFields[][100], uint nscalars, char vectorFields[][100], uint nvectors, uint* timeList, uint ntimes  ) {



    // Open File

    FILE *outFile;
    
    outFile = fopen("lbm.case", "w");


    fprintf(outFile,"#\n");
    fprintf(outFile,"# EnSight 7.4.1 ((n))\n");
    fprintf(outFile,"# Case File: lattice.case\n");
    fprintf(outFile,"\n");
    fprintf(outFile,"FORMAT\n");
    fprintf(outFile,"\n");
    fprintf(outFile,"type:  ensight gold\n");
    fprintf(outFile,"\n");
    fprintf(outFile,"GEOMETRY\n");
    fprintf(outFile,"\n");
    fprintf(outFile,"model:                     lattice.geo\n");
    fprintf(outFile,"\n");
    fprintf(outFile,"VARIABLE\n");
    fprintf(outFile,"\n");

		
    for( uint fid = 0 ; fid < nscalars ; fid++ )
	fprintf(outFile,"scalar per node:           %s lattice.%s_*\n",scalarFields[fid],scalarFields[fid]);

	
    for( uint fid = 0 ; fid < nvectors ; fid++ )
	fprintf(outFile,"vector per node:           %s lattice.%s_*\n",vectorFields[fid],vectorFields[fid]);
	    


	
    fprintf(outFile,"\n");
	
    fprintf(outFile,"TIME\n");

    fprintf(outFile,"time set:                  1\n");

    fprintf(outFile,"number of steps:           %d\n", ntimes);

    fprintf(outFile,"filename start number:     0\n");

    fprintf(outFile,"filename increment:        1\n");

    fprintf(outFile,"time values:               %d\n", timeList[0]);

    for( uint i = 1 ; i < ntimes; i++ )
	fprintf(outFile,"                           %d\n", timeList[i]);


    fclose(outFile);

    
}
