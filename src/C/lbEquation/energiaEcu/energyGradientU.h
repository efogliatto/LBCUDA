#ifndef ENERGYGRADIENTU_H
#define ENERGYGRADIENTU_H

/**
 * @file energyGradientU.h
 * @author Thomás Coronel
 * @date 23 Mar 2020
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

 */

#include <basicMesh.h>

void energyGradientU( basicMesh* mesh, scalar* gradient, scalar* field, scalar* velocity, int comp_vel, int node_i, scalar cs_2, scalar delta_t) ;



#endif // ENERGYGRADIENTU_H

// La función existe debido a que para realizar el cálculo del grradiente de Ux,Uy,Uz se deberia copiar los datos, lo cual ocuparía mucha memoria, por ello se optó de realizar esta función.
