#ifndef BASICMESH_H
#define BASICMESH_H

/**
 * @file basicMesh.h
 * @author Ezequiel O. Fogliatto
 * @date 27 Ene 2020
 * @brief Estructura de grilla para LB
 */

#include <dataTypes.h>

#include <latticeModelInfo.h>


/**
 * @brief Boundary information
 *
 * Information about boundary elements
 */

typedef struct {

    /** Numero total de fronteras */
    
    uint nbd;
    

    /** Numero de elementos por frontera */
    
    uint* nbdelem;


    /** Nombre de fronteras */
    
    char bdNames[100][100];


    /** Indice de nodos para cada frontera */
    
    uint** bdPoints;

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
    
    int** vtkCells;

   

    /** Fronteras */

    basicBoundary bd;


    /** Constantes del modelo de grilla */

    latticeModelInfo lattice;
    

} basicMesh;





#endif // BASICMESH_H
