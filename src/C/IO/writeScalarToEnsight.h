#ifndef WRITESCALARTOENSIGHT_H
#define WRITESCALARTOENSIGHT_H

#include <basicMesh.h>

/**
 * @file writeScalarToEnsight.h
 * @author Ezequiel O. Fogliatto
 * @date 3 Apr 2020
 * @brief Escritura de campo escalar en formato Ensight
 */

/**
 * Escritura de campo escalar en fromato Ensight
 */

void writeScalarToEnsight( char* fname, scalar* field, basicMesh* mesh, uint fcount );

#endif // WRITESCALARTOENSIGHT_H
