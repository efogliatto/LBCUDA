#ifndef CUDABASICMESH_H
#define CUDABASICMESH_H

/**
 * @file cudaBasicMesh.h
 * @author Ezequiel O. Fogliatto
 * @date 28 Ene 2020
 * @brief Estructura de grilla para device
 */


/**
 * @brief Informaci\'on b\'asica de grilla
 *
 * Informaci\'on de grilla
 */

#include <dataTypes.h>

typedef struct {

    
    /**< Numero total de puntos */
    
    uint nPoints;   

    
    /**< Arreglo uinidimensional de coordenadas */
    
    int* points;   
    

    /**< Numero total de vecinos por celda */    
    
    uint Q;


    /**< Dimension */        

    uint D;


    /**< Nombre del modelo de grilla LB (tipo DdQq) */
    
    char lbm[100];


    /**< Arreglo uinidimensional de vecinos */
    
    int* nb;

   


} cudaBasicMesh;





#endif // CUDABASICMESH_H
