#ifndef ENERGYEQDISTNODE_H
#define ENERGYEQDISTNODE_H

/**
 * @file energyEqDistNode.h
 * @author Ezequiel Fogliatto
 * @date 13 Apr 2020
 * @brief Distribución de equilibrio en espacio de momento para ecuación de energía
 */



#include <basicMesh.h>

#include <energyCoeffs.h>

void energyEqDistNode( scalar* eq, basicMesh* mesh, scalar* T, scalar* U, uint id, scalar alpha_1, scalar alpha_2 );

#endif // ENERGYQDISTNODE_H
