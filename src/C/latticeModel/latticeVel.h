#ifndef LATTICEVEL_H
#define LATTICEVEL_H

#include <D2Q9.h>

#include <latticeModelInfo.h>

/**
 * @file latticeVel.h
 * @author Ezequiel O. Fogliatto
 * @date 14 Feb 2020
 * @brief Lattice velocities in one dimensional array
 */


/**
 * Lattice velocities
 * @return Array of lattice velocities as integer indices. One dimensional array
 */

int* latticeVel( DdQq model );

#endif // LATTICEVEL_H
