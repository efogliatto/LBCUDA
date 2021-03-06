#ifndef ZEROTHMOMENT_H
#define ZEROTHMOMENT_H

/**
 * @file zerothMoment.h
 * @author Ezequiel O. Fogliatto
 * @date 28 Ene 2020
 * @brief C\'alculo de momento de orden cero para arreglo unidimensional
 */


/**
 * C\'alculo de momento de orden cero para arreglo unidimensional
 * @param field Arreglo unidimensional de la funcion de distribucion
 * @param zeroth Arreglo unidimensional resultante
 * @param mesh Malla
 */

#include <dataTypes.h>

#include <cudaBasicMesh.h>


extern "C" __global__ void zerothMoment(cuscalar* field, cuscalar* zeroth, int np, int Q );


#endif // ZEROTHMOMENT_H
