#ifndef THOMASMODEL_H
#define THOMASMODEL_H

/**
 * @file thomasModel.h
 * @author Thomas Coronel	
 * @date 4 Feb 2020
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


extern "C" __global__ void thomasModel(cuscalar* field, cuscalar* zeroth, int np, int Q );


#endif // THOMASMODEL_H
