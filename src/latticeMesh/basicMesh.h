#ifndef BASICMESH_H
#define BASICMESH_H

/**
 * @file basicMesh.h
 * @author Ezequiel O. Fogliatto
 * @date 27 Ene 2020
 * @brief Estructura de grilla para LB
 */

#include "dataTypes.h"

/* /\** */
/*  * @brief Boundary information */
/*  * */
/*  * Information about boundary elements */
/*  *\/ */

/* typedef struct { */
    
/*     uint nbd;         /\**< Number of boundary types *\/ */
    
/*     std::vector<uint> nbdelem;    /\**< Total number of elements per boundary type *\/ */
    
/*     std::vector<std::string> bdNames;   /\**< Boundary names *\/ */
    
/*     std::vector< std::vector<uint> > bdPoints;  /\**< Elements in boundary *\/ */

/* } basicBoundary; */



/**
 * @brief Informaci\'on b\'asica de grilla
 *
 * Informaci\'on de grilla
 */

typedef struct {

    
    /**< Numero total de puntos */
    
    uint nPoints;   

    
    /**< Arreglo de coordenadas */
    
    int** points;   
    

    /**< Numero total de vecinos por celda */    
    
    uint Q;


    /**< Dimension */        

    uint D;


    /**< Nombre del modelo de grilla LB (tipo DdQq) */
    
    char lbm[100];


    /**< Arreglo de vecinos */
    
    int** nb;


    
    /* basicBoundary bd;   /\**< Boundary information *\/ */

    
    /* uint ncells;   /\**< Number of VTK cells per patch *\/ */
    
    /* uint cellType;   /\**< VTK cell type *\/ */
    
    /* std::vector< std::vector<int> > vtkCells;   /\**< VTK cell indices array *\/ */


    /* /\** Array with cell conectivity *\/ */

    /* std::vector< std::vector<uint> > nodeToCells; */


} basicMesh;





#endif // BASICMESH_H
