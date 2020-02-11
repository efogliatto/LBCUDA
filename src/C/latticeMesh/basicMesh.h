#ifndef BASICMESH_H
#define BASICMESH_H

/**
 * @file basicMesh.h
 * @author Ezequiel O. Fogliatto
 * @date 27 Ene 2020
 * @brief Estructura de grilla para LB
 */

#include "dataTypes.h"


/**
 * @brief Boundary information
 *
 * Information about boundary elements
 */

typedef struct {
    
    uint nbd;         /**< Number of boundary types */
    
    uint* nbdelem;    /**< Total number of elements per boundary type */
    
    char bdNames[100][100];   /**< Boundary names (max 100 boundaries) */
    
    uint** bdPoints;  /**< Elements in boundary */

} basicBoundary;



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


  


    /** Numero total de celdas */
    
    uint ncells;


    /** Tipo de celda (VTK) */
    
    uint cellType;


    /** Arreglo de celdas */
    
    uint** vtkCells;

   

    /** Fronteras */

    basicBoundary bd;
    

} basicMesh;





#endif // BASICMESH_H
