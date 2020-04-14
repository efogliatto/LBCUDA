#ifndef BOUNDARYINDEX_H
#define BOUNDARYINDEX_H

/**
 * @file boundaryIndex.h
 * @author Ezequiel O. Fogliatto
 * @date 14 Apr 2020
 * @brief Indice correspondiente a nombre de frontera
 */


#include <basicMesh.h>

__host__ void boundaryIndex( basicMesh* mesh, const char* bdname, uint* idx);

#endif // BOUNDARYINDEX_H
