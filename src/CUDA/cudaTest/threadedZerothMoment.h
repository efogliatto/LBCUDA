#ifndef THREADEDZEROTHMOMENT_H
#define THREADEDZEROTHMOMENT_H

/**
 * @file threadedZerothMoment.h
 * @author Ezequiel O. Fogliatto
 * @date 31 Ene 2020
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


extern "C" __global__ void threadedZerothMoment(cuscalar* field, cuscalar* zeroth, int np, int Q );


#endif // THREADEDZEROTHMOMENT_H
