#ifndef CUDATHREADEDMATMULT_H
#define CUDATHREADEDMATMULT_H

/**
 * @file cudaThreadedMatMult.h
 * @author Ezequiel O. Fogliatto
 * @date 17 Feb 2020
 * @brief Kernel para multiplicacion de matriz vector
 */


/**
 * Kernel para multiplicacion de matriz vector
 * @param res Arregle de salida
 * @param mat Matriz como arreglo unidimensional
 * @param vec* Funcion de distribucion como arreglo unidimensional
 * @param id Indice de nodo
 * @param Q Cantidad de vecinos
 */

#include <dataTypes.h>

extern "C" __global__ void cudaThreadedMatMult(cuscalar* mat, cuscalar* vec, uint id, uint Q);

#endif // CUDATHREADEDMATMULT_H
