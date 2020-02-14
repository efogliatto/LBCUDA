#ifndef MRT_MATRIX_H
#define MRT_MATRIX_H

/**
 * @file MRT_Matrix.h
 * @author Ezequiel O. Fogliatto
 * @date 11 Feb 2020
 * @brief Matriz de colision MRT
 */

/**
 * Matriz de colision MRT
 * @return Matriz de colision como arreglo unidimensional
 */


#include <latticeModelInfo.h>

scalar* MRT_Matrix( DdQq model );

#endif // MRT_MATRIX_H
