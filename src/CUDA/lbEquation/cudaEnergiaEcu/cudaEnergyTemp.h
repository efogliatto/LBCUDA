#ifndef CUDAENERGYTEMP_H
#define CUDAENERGYTEMP_H

/**
 * @file cudaEnergyTemp.h
 * @author Thomás Coronel
 * @date 24 Mar 2020
 * @brief Calculo de Temperatura
 */


/**
 * Calculo de Temperatura
 * 
 *  $ \mathbf{T} = \mathbf{\sum\limits_{\alpha} g_{\alpha}} + \frac{1}{2} \mathbf{\delta_{t} \hat{\gamma}} $
 *
 * @param T Temperatura
 * @param field Función de distribución
 * @param gamma_0 Primer término de la fuente de espacios de momentos
 * @param delta_t Paso de tiempo
 * @param np Numero de puntos
 * @param Q Cantidad de vecinos 
 */

#include <basicMesh.h>

extern "C" __global__ void cudaEnergyTemp( cuscalar* T, cuscalar* field, cuscalar* gamma_0, cuscalar delta_t, unit np, int Q) ;


#endif // CUDAENERGYTEMP_H
