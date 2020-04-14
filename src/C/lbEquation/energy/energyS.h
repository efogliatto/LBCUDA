#ifndef ENERGYS_H
#define ENERGYS_H

/**
 * @file energyS.h
 * @author Thomás Coronel
 * @date 23 Mar 2020
 * @brief Primer elemento del término de fuente \Gamma de la ecuación de energía
 */

/**
 * Término de la fuente de energía s
 *
 * $ \mathbf{s} = \mathbf{\frac{\chi}{\rho}} \> \left( \mathbf{\frac{\delta T}{\delta x}} \mathbf{\frac{\delta \rho}{\delta x}} + \mathbf{\frac{\delta T}{\delta y}} \mathbf{\frac{\delta \rho}{\delta y}} + \mathbf{\frac{\delta T}{\delta z}} \mathbf{\frac{\delta \rho}{\delta z}} \right) + T \left[ \mathbf{1} - \mathbf{\frac{1}{\rho c_{v}}} {\left( \mathbf{\frac{\delta p_{\>EOS}}{\delta T}} \right)}_{\rho} \right] \left( \mathbf{\frac{\delta U_{x}}{\delta x}} + \mathbf{\frac{\delta U_{y}}{\delta y}} + \mathbf{\frac{\delta U_{z}}{\delta z}} \right)  $
 *
 * $ \mathbf{\chi} = \mathbf{\delta_{\>t}} \left(\mathbf{\frac{1}{q_{3}}} - \mathbf{\frac{1}{2}}    \right) \left( \mathbf{\frac{4+3 \alpha_1 + 2\alpha_2}{6}}\right) $
 * 
 * @param mesh Estructura basica de grilla
 * @param s Primer término de la fuente en la ecuación de energía
 * @param rho Densidad
 * @param T Temperatura
 * @param U Velocidad
 * @param relax Coeficientes de relajación diagonal (Q)
 * @param field Campo a colisionar
 * @param alpha_1 Parámetro de ajuste del modelo
 * @param alpha_2 Parámetro de ajuste del modelo
 * @param cs_2 Parametro del modelo de LB elevado al cuadrado
 * @param delta_t Paso de tiempo
 * @param c_v Calor específico a volumen constante
 * @param b Parametro del modelo DdQq
 */


#include <basicMesh.h>

#include <energyCoeffs.h>

void energyS( basicMesh* mesh, scalar* s, scalar* rho, scalar* T, scalar* U, energyCoeffs* relax, scalar cs_2, scalar delta_t, scalar b) ;

#endif // ENERGYS_H
