#ifndef UPDATECASEFILE_H
#define UPDATECASEFILE_H

/**
 * @file updateCaseFile.h
 * @author Ezequiel O. Fogliatto
 * @date 3 Apr 2020
 * @brief Escritura de archivo maestro para formato Ensight
 */

/**
 * Escritura de achivo maestro para formato Ensight
 */


#include <stdlib.h>

#include <stdio.h>

void updateCaseFile( char scalarFields[][100], uint nscalars, char vectorFields[][100], uint nvectors, uint* timeList, uint ntimes );

#endif // UPDATECASEFILE_H
