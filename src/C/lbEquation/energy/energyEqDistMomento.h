#ifndef ENERGYEQDISTMOMENTO_H
#define ENERGYEQDISTMOMENTO_H

/**
 * @file energyEqDistMomento.h
 * @author Ezequiel Fogliatto
 * @date 13 Apr 2020
 * @brief Distribución de equilibrio en espacio de momento para ecuación de energía
 */



#include <basicMesh.h>

#include <energyCoeffs.h>

void energyEqDistMomento( basicMesh* mesh, scalar* field, scalar* T, scalar* U, energyCoeffs* relax );

#endif // ENERGYQDISTMOMENTO_H
