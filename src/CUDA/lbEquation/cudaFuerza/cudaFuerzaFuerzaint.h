#ifndef CUDAFUERZAFUERZAINT_H
#define CUDAFUERZAFUERZAINT_H

/**
 * @file cudaFuerzaFuerzaint.h
 * @author Thomas Coronel
 * @date 27 Feb 2020
 * @brief Calculo de Fuerza de Interaccion
 */


/**
 * Calculo de fuerza de interaccion
 * @param fint Fuerza de Interaccion
 * @param psi Valor de la funcion
 * @param np Numero de puntos
 * @param Q Cantidad de vecinos 
 * @param nb Matriz de vecinos
 * @param G Parametro del modelo de LB

 */

#include <basicMesh.h>

extern "C" __global__ void cudaFuerzaFuerzaint(scalar* fint, scalar* psi, int np, int Q,  int* lvel,int* nb, scalar G)   ;


#endif // CUDAFUERZAFUERZAINT_H
