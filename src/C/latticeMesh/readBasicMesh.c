#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <readBasicMesh.h>
#include <latticeModel.h>
#include <basic.h>


basicMesh readBasicMesh() {

    basicMesh mesh;

    uint i,j;

    int status;

    

    // ******************************************************************** //
    //                         Points inside geometry                       //
    // ******************************************************************** //

    printf(" Lectura de puntos\n\n");

    
    // Open file

    FILE* inFile = fopen( "lattice/points", "r" );

    
    // Number of points

    int iaux;    

    status = fscanf(inFile, "%d", &iaux);

    mesh.nPoints = (uint)iaux;

    
    // Read Mesh points

    status = int2dArray(&mesh.points, mesh.nPoints, 3, 0);

    for( i = 0 ; i < mesh.nPoints ; i++ ) {

	status = fscanf(inFile, "%d", &mesh.points[i][0]);
	status = fscanf(inFile, "%d", &mesh.points[i][1]);
	status = fscanf(inFile, "%d", &mesh.points[i][2]);

    }

    fclose(inFile);





    

    // ******************************************************************** //
    //                             Neighbours                               //
    // ******************************************************************** //

    printf(" Lectura de índices de vecinos\n\n");
    

    // Open file
    
    inFile = fopen( "lattice/neighbours", "r" );

    status = fscanf(inFile, "%d", &iaux);
    
    status = fscanf(inFile, "%d", &iaux);    

    mesh.Q = (uint)iaux;

    if( mesh.Q == 9 ) {

	mesh.D = 2;

    }

    else {

	mesh.D = 3;

    }





    
    // Read neighbours
    
    status = int2dArray(&mesh.nb, mesh.nPoints, mesh.Q, -1);

    for( i = 0 ; i < mesh.nPoints ; i++ ) {

	for( j = 0 ; j < mesh.Q ; j++ ) {

	    status = fscanf(inFile, "%d", &mesh.nb[i][j]);

	}

    }

    fclose(inFile);





    // Asignacion de propiedades de grilla

    if( (mesh.D == 2)  &&  (mesh.Q == 9) ) {

	mesh.lattice.model = D2Q9;

    }

    mesh.lattice.q = mesh.Q;

    mesh.lattice.d = mesh.D;

    mesh.lattice.vel     = latticeVel( mesh.lattice.model );

    mesh.lattice.reverse = latticeReverseDir( mesh.lattice.model );

    mesh.lattice.M       = MRT_Matrix( mesh.lattice.model );

    mesh.lattice.invM    = MRT_invMatrix( mesh.lattice.model );        


    

    

    // ******************************************************************** //
    //                             VTK Cells                                //
    // ******************************************************************** //

    printf(" Lectura de celdas\n\n");

    // Open file
    inFile = fopen( "lattice/vtkCells", "r" );

    // Number of cells and points per cell
    status = fscanf(inFile, "%d", &iaux);
    mesh.ncells = (uint)iaux;
    
    status = fscanf(inFile, "%d", &iaux);
    mesh.cellType = (uint)iaux;
    
    // Read cells
    status = int2dArray( &mesh.vtkCells, mesh.ncells, mesh.cellType, -1);
    
    for( i = 0 ; i < mesh.ncells ; i++ ) {

    	for( j = 0 ; j < mesh.cellType ; j++ ) {

    	    status = fscanf(inFile, "%d", &mesh.vtkCells[i][j]);

    	}

    }

    fclose(inFile);








    // ******************************************************************** //
    //                        Reading boundary nodes                        //
    // ******************************************************************** //

    printf(" Lectura de nodos de frontera\n\n");

    // Open boundary file
    inFile = fopen( "lattice/boundary", "r" );
    
    // Number of boundary types
    status = fscanf(inFile, "%d\n", &iaux);
    mesh.bd.nbd = (uint)iaux;
    
    // Total number of elements per boundary type
    mesh.bd.nbdelem = (uint*)malloc(mesh.bd.nbd * sizeof(uint));

    // Elements in boundary
    mesh.bd.bdPoints = (uint**)malloc( mesh.bd.nbd * sizeof(uint*) );
    

    // Read boundary
    for( i = 0 ; i < mesh.bd.nbd ; i++ ) {

    	// Boundary name
    	status = fscanf(inFile, "%s", mesh.bd.bdNames[i]);

    	// Elements in boundary
    	status = fscanf(inFile, "%d", &iaux);
    	mesh.bd.nbdelem[i] = (uint)iaux;

    	// Resize bdPoints
    	mesh.bd.bdPoints[i] = (uint*)malloc( mesh.bd.nbdelem[i] * sizeof(uint) );
	
    	for( j = 0 ; j < mesh.bd.nbdelem[i] ; j++ ) {

    	    status = fscanf(inFile, "%d", &iaux);
    	    mesh.bd.bdPoints[i][j] = (uint)iaux;

    	}

    }
    

    fclose(inFile);



    
    if (status) {}
    
    return mesh;
    
}
