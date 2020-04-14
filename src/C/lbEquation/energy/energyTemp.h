#ifndef ENERGYTEMP_H
#define ENERGYTEMP_H

/**
 * @file energyTemp.h
 * @author Thomás Coronel
 * @date 23 Mar 2020
 * @brief Calculo de Temperatura
 */


/**
 * Calculo de Temperatura
 * 
 *  $ \mathbf{T} = \mathbf{\sum\limits_{\alpha} g_{\alpha}} + \frac{1}{2} \mathbf{\delta_{t} \hat{\gamma}} $
 *
 * @param mesh Malla básica 
 * @param T Temperatura
 * @param field Función de distribución
 * @param gamma_0 Primer término de la fuente de espacios de momentos
 * @param delta_t Paso de tiempo
 
 */

#include <basicMesh.h>

void energyTemp( basicMesh* mesh, scalar* T, scalar* field, scalar* gamma_0, scalar delta_t ) ;


#endif // ENERGYTEMP_H
