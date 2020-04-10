#ifndef CUDAFUERZAFUERZAINT_H
#define CUDAFUERZAFUERZAINT_H

/**
 * @file cudaFuerzaFuerzaint.h
 * @author Thomás Coronel
 * @date 27 Feb 2020
 * @brief Calculo de Fuerza de Interaccion
 */


/**
 * Calculo de fuerza de interaccion
 * @param fint Fuerza de Interaccion
 * @param rho Densidad macroscópica
 * @param T Temperatura macroscópica
 * @param np Numero de puntos
 * @param Q Cantidad de vecinos 
 * @param lvel Velocidades de grilla
 * @param nb Matriz de vecinos
 * @param G Parametro del modelo de LB
 * @param c Parametro del modelo de LB
 * @param cs_2 Parametro del modelo de LB elevado al cuadrado
 * @param a Parametro del modelo DdQq
 * @param b Parametro del modelo DdQq
 */

#include <basicMesh.h>

extern "C" __global__ void cudaFuerzaFuerzaint(cuscalar* fint, cuscalar* rho, cuscalar* T, int np, int Q,
					       int* lvel, int* reverse, int* nb, cuscalar G, cuscalar c, cuscalar cs_2, cuscalar a, cuscalar b)   ;


#endif // CUDAFUERZAFUERZAINT_H
