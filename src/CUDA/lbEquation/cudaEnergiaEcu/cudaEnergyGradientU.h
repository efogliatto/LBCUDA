#ifndef CUDAENERGYGRADIENTU_H
#define CUDAENERGYGRADIENTU_H

/**
 * @file cudaEnergyGradientU.h
 * @author Thomás Coronel
 * @date 24 Mar 2020
 * @brief Cálculo del gradiente de una componente de la velocidad.
 */

/**
 * Calculo del gradiente de uno de los componentes de la velocidad
 * 
 * $ \mathbf{\nabla U_x} = \mathbf{\sum\limits_{i \neq 0}\frac{f_i {U_x}_i \bar{e}}{{c_s}^{2}  \delta_{t}} }$
 * 
 * @param mesh Malla básica
 * @param gradiente Gradiente calculado en las tres dimensiones
 * @param field Función de distribución
 * @param velocity Velocidad 
 * @param comp_velo Componente de la velocidad que se le calcula el gradiente (x=0,y=1,Z=2)
 * @param cs_2 Constante relacionado a la velocidad del sonido en el medio sdependiente del modelo de LB
 * @param delta_t Paso de tiempo
 * @param node_i Nodo de la malla en que se está realizando el cálculo
 * @param Q Cantidad de vecinos 
 * @param lvel Velocidades de grilla
 * @param nb Matriz de vecinos
 */

#include <basicMesh.h>

extern "C" __device__ void cudaEnergyGradientU( cuscalar* gradient, cuscalar* field, cuscalar* velocity, int comp_vel, int node_i, cuscalar cs_2, cuscalar delta_t, int Q,  int* lvel,int* nb) ;



#endif // CUDAENERGYGRADIENTU_H

// La función existe debido a que para realizar el cálculo del grradiente de Ux,Uy,Uz se deberia copiar los datos, lo cual ocuparía mucha memoria, por ello se optó de realizar esta función.
