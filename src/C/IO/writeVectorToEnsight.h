#ifndef WRITEVECTORTOENSIGHT_H
#define WRITEVECTORTOENSIGHT_H

#include <basicMesh.h>

/**
 * @file writeVectorToEnsight.h
 * @author Ezequiel O. Fogliatto
 * @date 3 Apr 2020
 * @brief Escritura de campo vectorial en formato Ensight
 */

/**
 * Escritura de campo vectorial en formato Ensight
 */

#include <basicMesh.h>

void writeVectorToEnsight( char* fname, scalar* field, basicMesh* mesh, uint fcount );

#endif // WRITEVECTORTOENSIGHT_H
