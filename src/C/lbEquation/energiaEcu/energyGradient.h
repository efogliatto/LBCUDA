#ifndef ENERGYGRADIENT_H
#define ENERGYGRADIENT_H

/**
 * @file energyGradient.h
 * @author Thomas Coronel
 * @date 12 Mar 2020
 * @brief Calculo del gradiente de una variable escalar 
 */

/**
 * Calculo de densidad
 * @param mesh Malla básica
 * @param gradiente Gradiente calculado en las tres dimensiones
 * @param field Función de distribución
 * @param variable Variable escalar a la cual se le esta calculando el gradiente
 * @param cs_2 Constante relacionado a la velocidad del sonido en el medio sdependiente del modelo de LB
 * @param delta_t Paso de tiempo

 */

#include <basicMesh.h>

void energyGradient( basicMesh* mesh, scalar* gradient, scalar* field, scalar* variable, scalar cs_2, scalar delta_t);



#endif // ENERGYGRADIENT_H
