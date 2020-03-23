#ifndef CUDAMOMENTOCOLLISION_H
#define CUDAMOMENTOCOLLISION_H

/**
 * @file cudaMomentoCollision.h
 * @author Thomás Coronel
 * @date 20 Feb 2020
 * @brief Operaci\'on de modelo de colisi\'on simplificado
 */


/**
 * Operaci\'on de modelo de colisi\'on simplificado
 * @param field Arreglo unidimensional de la funcion de distribucion
 * @param sum Arreglo unidimensional resultante
 * @param mesh Malla
 * @param delta_t Paso de tiempo
 * @param p_EOS Presion
 * @param psi Funcion psi
 */

#include <dataTypes.h>

#include <cudaLatticeMesh.h>


extern "C" __global__ void cudaMomentoCollision( cuscalar* field, cuscalar* rho, cuscalar* U, cuscalar* f, cuscalar* fint, cuscalar* T, cuscalar* Tau, cuscalar* M, cuscalar* invM, uint np, uint Q, cuscalar delta_t, int a, int b, cuscalar c, cuscalar cs_2, cuscalar G, cuscalar sigma) ;


#endif // CUDAMOMENTOCOLLISION_H
