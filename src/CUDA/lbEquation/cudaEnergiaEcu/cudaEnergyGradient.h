#ifndef CUDAENERGYGRADIENT_H
#define CUDAENERGYGRADIENT_H

/**
 * @file cudaEnergyGradient.h
 * @author Thomás Coronel
 * @date 24 Mar 2020
 * @brief Cálculo del gradiente de una variable escalar 
 */

/**
 * Cálculo del gradiente de una variable escalar
 * 
 * $ \mathbf{\nabla \xi} = \mathbf{\sum\limits_{i \neq 0}\frac{f_i \xi_i \bar{e}}{{c_s}^{2}  \delta_{t}} }$
 * 
 * @param gradiente Gradiente calculado en las tres dimensiones
 * @param field Función de distribución
 * @param variable Variable escalar a la cual se le esta calculando el gradiente
 * @param cs_2 Constante relacionado a la velocidad del sonido en el medio sdependiente del modelo de LB
 * @param node_i Nodo de la malla en que se está realizando el cálculo
 * @param delta_t Paso de tiempo
 * @param Q Cantidad de vecinos 
 * @param lvel Velocidades de grilla
 * @param nb Matriz de vecinos
 */

#include <basicMesh.h>

extern "C" __device__ void cudaEnergyGradient( cuscalar* gradient, cuscalar* field, cuscalar* variable, int node_i, cuscalar cs_2, cuscalar delta_t, int Q,  int* lvel,int* nb);



#endif // CUDAENERGYGRADIENT_H
