/*

  latticeBox2D

  lattice generation in a 2D Box

*/

/* #include <io.h> */
/* #include <dictIO.h> */
/* #include <latticeModel.h> */
/* #include <basic.h> */


/* void periodicX( basicMesh* mesh, uint nx, uint ny ); */
/* void periodicY( basicMesh* mesh, uint nx, uint ny ); */
/* void periodicXY( basicMesh* mesh, uint nx, uint ny ); */
/* void genericBoundary( basicMesh* mesh, uint nx, uint ny ); */




#include <stdio.h>


int main(int argc, char** argv) {

    
    printf( "                    \n" );
    printf( "     o-----o-----o  \n" );
    printf( "     | -   |   - |  \n" );
    printf( "     |   - | -   |  \n" );
    printf( "     o<----o---->o  Grilla bidimensional en dominio rectangular\n" );
    printf( "     |   - | -   |  \n" );
    printf( "     | -   |   - |  \n" );
    printf( "     o-----o-----o  \n" );



    
    /* // Basic lattice properties */

    /* basicMesh mesh; */

    /* uint status; */
    

    /* // Lattice size */

    /* scalar dn; */

    /* uint nx = 0, */
    /* 	ny = 0;     */

    /* if(  lookUpScalarEntry("properties/latticeProperties", "Nx", -1, &dn)  ) */
    /* 	nx = (uint)dn; */

    /* if(  lookUpScalarEntry("properties/latticeProperties", "Ny", -1, &dn)  ) */
    /* 	ny = (uint)dn;     */


    /* mesh.nPoints = nx*ny; */




    
    /* // Lattice model */

    /* char* modelName; */
    
    /* latticeInfo lattice; */

    /* lattice.model = D2Q9; */
    
    /* status = lookUpStringEntry( "properties/latticeProperties", "LBModel", &modelName, "D2Q9" ); */

    /* if(status) {} */

    /* if( strcmp(modelName, "D2Q9") == 0 ) { */

    /* 	lattice.model = D2Q9; */

    /* } */

    /* else { */

    /* 	if( strcmp(modelName, "D3Q15") == 0 ) { */

    /* 	    lattice.model = D3Q15; */

    /* 	} */

    /* 	else { */

    /* 	    char msg[100]; */

    /* 	    sprintf(msg, "Unrecognized model %s", modelName); */
	    
    /* 	    errorMsg( msg ); */

    /* 	} */

    /* } */
    
    

  



    

    /* // ******************************************************************** // */
    /* //                         Points inside geometry                       // */
    /* // ******************************************************************** // */

    
    /* printf("Adding points to lattice\n\n"); */

    /* mesh.points = matrixIntAlloc(mesh.nPoints,3,0); */

        
    /* // Move over indices */

    /* int i,j; */

    /* for( j = 0 ; j < ny ; j++) { */
	
    /* 	for( i = 0 ; i < nx ; i++) { */
			    
    /* 	    mesh.points[i+j*nx][0] = i; */
    /* 	    mesh.points[i+j*nx][1] = j; */
		
    /* 	} */
    /* } */




    
    

    /* // ******************************************************************** // */
    /* //                             Neighbours                               // */
    /* // ******************************************************************** // */

    
    /* printf("Computing neighbour indices\n\n"); */

    
    /* // Lattice velocities */
    
    /* int** velocities = latticeVelocities(lattice.model); */

    /* int* rev = latticeReverseDir(lattice.model); */

    
    
    /* // Create and resize neighbour matrix */
    
    /* mesh.Q = latticeQ( lattice.model ); */

    /* mesh.nb = matrixIntAlloc(mesh.nPoints, mesh.Q,-1); */
    

    

    /* // Check for neighbouring */
    /* // There is no need to iterate over all points to look for a neighbour. Given a lattice velocity vector (x,y,z), the neighbour of a point */
    /* // p with index pointId is at most at pointId + x + (y*Nx). */

    
    /* // Internal points first */

    /* int pointId, velId; */
    
    /* for( j = 1 ; j < (ny-1) ; j++) { */
	
    /* 	for( i = 1 ; i < (nx-1) ; i++) { */

    /* 	    pointId = i+j*nx; */


    /* 	    // Iterate on velocities */
    /* 	    for( velId = 0 ; velId < mesh.Q ; velId++ ) { */

    /* 		mesh.nb[pointId][velId] = pointId   +   velocities[ rev[velId] ][0]   +   velocities[ rev[velId] ][1] * nx; */

    /* 	    } */
	    
    /* 	} */

    /* } */

    

    /* // For boundary nodes, check neighbouring using distance to point */

    /* for( j = 0 ; j < ny ; j+=(ny-1)) { */
	
    /* 	for( i = 0 ; i < nx ; i++) { */

    /* 	    pointId = i+j*nx; */

    /* 	    // Iterate on velocities */
    /* 	    for( velId = 0 ; velId < mesh.Q ; velId++ ) { */

    /* 		int newId = pointId   +   velocities[ rev[velId] ][0]   +   velocities[ rev[velId] ][1] * nx; */

    /* 		if( newId >= 0   &&   newId <= nx*ny-1 ) { */

    /* 		    if ( (  abs( mesh.points[pointId][0] - mesh.points[newId][0] ) <= 1  )   &&   (  abs( mesh.points[pointId][1] - mesh.points[newId][1] ) <= 1  )  ) { */
	    
    /* 			mesh.nb[pointId][velId] = newId; */

    /* 		    } */

    /* 		} */

    /* 	    } */
	    
    /* 	} */

    /* } */


    /* for( j = 1 ; j < ny-1 ; j++ ) { */
	
    /* 	for( i = 0 ; i < nx ; i+=(nx-1)) { */

    /* 	    pointId = i+j*nx; */

    /* 	    // Iterate on velocities */
    /* 	    for( velId = 0 ; velId < mesh.Q ; velId++ ) { */

    /* 		int newId = pointId   +   velocities[ rev[velId] ][0]   +   velocities[ rev[velId] ][1] * nx; */

    /* 		if( newId >= 0   &&   newId <= nx*ny-1 ) { */

    /* 		    if ( (  abs( mesh.points[pointId][0] - mesh.points[newId][0] ) <= 1  )   &&   (  abs( mesh.points[pointId][1] - mesh.points[newId][1] ) <= 1  )  ) { */
	    
    /* 			mesh.nb[pointId][velId] = newId; */

    /* 		    } */

    /* 		} */

    /* 	    } */
	    
    /* 	} */

    /* } */
    


    	




    

	    
    
    /* // ******************************************************************** // */
    /* //                             Boundary                                 // */
    /* // ******************************************************************** // */

    /* printf("Computing boundary nodes\n\n"); */

    /* sprintf(mesh.bd.bdNames[0],"X0"); */
    /* sprintf(mesh.bd.bdNames[1],"X1"); */
    /* sprintf(mesh.bd.bdNames[2],"Y0"); */
    /* sprintf(mesh.bd.bdNames[3],"Y1"); */

    
    /* // Boundary type */
    
    /* char* bdt; */

    /* status = lookUpStringEntry("properties/latticeProperties","boundaryType", &bdt, "generic"); */

    
    /* // Assign points on boundary based on bdType */

    /* // Generic */
    /* if( strcmp(bdt,"generic") == 0) { */

    /* 	genericBoundary( &mesh, nx, ny ); */

    /* } */


    /* // periodicX */
    /* else { */

    /* 	if( strcmp(bdt,"periodicX")  == 0 ) { */

    /* 	    periodicX( &mesh, nx, ny ); */

    /* 	} */


    /* 	// periodicY */
    /* 	else { */

    /* 	    if( strcmp(bdt,"periodicY")  == 0 ) { */

    /* 		periodicY( &mesh, nx, ny ); */

    /* 	    } */


    /* 	    // periodicXY */
    /* 	    else { */

    /* 		if( strcmp(bdt,"periodicXY")  == 0 ) { */

    /* 		    periodicXY( &mesh, nx, ny ); */

    /* 		} */

    /* 		else { */

    /* 		    printf("[ERROR]   Unrecognized boundary type %s\n\n", bdt); */
    /* 		    exit(0); */

    /* 		} */
	
    /* 	    } */
	
    /* 	} */

	
    /* } */
    




	    

    


    /* // ******************************************************************** // */
    /* //                             VTK Cells                                // */
    /* // ******************************************************************** // */

    /* printf("Creating VTK Cells\n\n"); */
    
    /* mesh.vtkCells = matrixIntAlloc((nx-1)*(ny-1),4,0); */

    /* mesh.ncells = 0; */
    /* mesh.cellType = 4; */
    
    /* for( j = 0 ; j < ny-1 ; j++ ) { */
	
    /* 	for( i = 0 ; i < (nx-1) ; i++ ) { */

    /* 	    mesh.vtkCells[mesh.ncells][0] = i + j*nx; */
    /* 	    mesh.vtkCells[mesh.ncells][1] = i + j*nx + 1; */
    /* 	    mesh.vtkCells[mesh.ncells][2] = i + j*nx + nx; */
    /* 	    mesh.vtkCells[mesh.ncells][3] = i + j*nx + nx + 1; */
	
    /* 	    mesh.ncells++; */

    /* 	} */

    /* } */
    

    



    


	    


    /* // ******************************************************************** // */
    /* //                             Writing                                  // */
    /* // ******************************************************************** // */
    
    /* printf("Writting Mesh\n\n"); */

    /* writeBasicMesh( &mesh ); */


    


    

    return 0;

}
