#include <energyS.h>

#include <energy.h>

#include <energyGradient.h>


#include <stdlib.h>

#include <stdio.h>

void energyS( basicMesh* mesh, scalar* s, scalar* rho, scalar* T, scalar* U, energyCoeffs* relax, scalar* field, scalar alpha_1, scalar alpha_2,  scalar cs_2, scalar delta_t, scalar c_v) {

        scalar chi = delta_t * ( ( 1 / relax->Tau[2]) -0.5 ) * ( (4 + 3 *alha_1 +2 * alpha_2 ) / 6.0 );
        scalar grad_Rho[3*];
        scalar grad_T[3*];
        scalar grad_Ux[3*];
        scalar grad_Uy[3*];
        scalar grad_Uz[3*mesh->];

        for( id = 0 ; id > mesh->nPoints , id++){

            scalar grad_T[3];
            
            energyGradient( mesh, grad_Rho, field, rho, cs_2, delta_t);


        }
}

