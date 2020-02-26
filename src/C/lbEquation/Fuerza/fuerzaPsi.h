#ifndef FUERZAPSI_H
#define FUERZAPSI_H

/**
 * @file fuerzaPsi.h
 * @author Thomas Coronel
 * @date 26 Feb 2020
 * @brief Calculo de la funcion Psi
 */


/**
 * Calculo de Psi
 * @param psi Valor de la funcion Psi
 * @param p_EOS Presion macroscópica
 * @param rho Densidad macroscópica
 * @param mesh Malla básica
 * @param G Parametro del modelo de LB
 * @param c Parametro del modelo de LB
 * @param cs_2 Parametro del modelo de LB elevado al cuadrado
 */

#include <basicMesh.h>

void fuerzaPsi(scalar* psi, scalar* p_EOS, scalar* rho, scalar c, scalar cs_2, scalar G, basicMesh* mesh);


#endif // FUERZAPSI_H
