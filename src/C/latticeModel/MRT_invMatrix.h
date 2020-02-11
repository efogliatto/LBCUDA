#ifndef MRT_INVMATRIX_H
#define MRT_INVMATRIX_H

/**
 * @file MRT_invMatrix.h
 * @author Ezequiel O. Fogliatto
 * @date 11 Feb 2020
 * @brief Matriz de colision MRT inversa
 */

/**
 * Matriz de colision MRT inversa
 * @return Matriz de colision inversa como arreglo unidimensional
 */


#include <latticeInfo.h>

int* MRT_invMatrix( DdQq model );

#endif // MRT_INVMATRIX_H
