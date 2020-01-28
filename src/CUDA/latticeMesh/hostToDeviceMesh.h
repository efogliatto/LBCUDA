#ifndef HOSTTODEVICEMESH_H
#define HOSTTODEVICEMESH_H

/**
 * @file hostToDeviceMesh.h
 * @author Ezequiel O. Fogliatto
 * @date 28 Ene 2020
 * @brief Copia de malla en host a device
 */

#include <cudaBasicMesh.h>
   
#include <basicMesh.h>


__host__ void hostToDeviceMesh(cudaBasicMesh* cmesh, basicMesh* hmesh);

#endif // HOSTTODEVICEMESH_H
