#ifndef LATTICEVELOCITIES_H
#define LATTICEVELOCITIES_H

#include "D2Q9.h"
#include "include/latticeInfo.h"

/**
 * @file latticeVelocities.h
 * @author Ezequiel O. Fogliatto
 * @date 27 Ene 2020
 * @brief Lattice velocities
 */


/**
 * Lattice velocities
 * @return Array of lattice velocities as integer indices
 */

int** latticeVelocities( DdQq model );

#endif // LATTICEVELOCITIES_H
