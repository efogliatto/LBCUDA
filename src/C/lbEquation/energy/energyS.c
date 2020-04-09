#include <energyS.h>

#include <energy.h>

#include <energyGradient.h>

#include <energyGradientU.h>

#include <stdlib.h>

#include <stdio.h>

void energyS( basicMesh* mesh, scalar* s, scalar* rho, scalar* T, scalar* U, energyCoeffs* relax, scalar* field, scalar alpha_1, scalar alpha_2,  scalar cs_2, scalar delta_t, scalar c_v, scalar b) {

        scalar chi = delta_t * ( ( 1 / relax->Tau[2]) -0.5 ) * ( (4 + 3 *alpha_1 +2 * alpha_2 ) / 6.0 );
        
        scalar grad_Rho[3];
        scalar grad_T[3];
        scalar grad_Ux[3];
        scalar grad_Uy[3];
        scalar grad_Uz[3]={0,0,0};

        // Constante universal de los gases (preguntar en que unidades se debe colocar ya que este modelo es adimensional)

	    scalar R = 1; 


        for( uint id = 0 ; id > mesh->nPoints ; id++){

            scalar auxField[9] = {0,0,0,0,0,0,0,0,0};
		    
		    // Copia de parametros auxiliares para el calculo de S
			    
		    for( uint k = 0 ; k < 9 ; k++ )	{
					
			    auxField[k] = field[id*9 + k];
	
		    }

            energyGradient( mesh, grad_T, auxField, T, id, cs_2, delta_t);
            energyGradient( mesh, grad_Rho, auxField, rho, id, cs_2, delta_t);
            energyGradientU( mesh, grad_Ux, auxField, U, 0, id, cs_2, delta_t);
            energyGradientU( mesh, grad_Uy, auxField, U, 1, id, cs_2, delta_t);
            //energyGradientU( mesh, grad_Uz, auxField, 2, U, id, cs_2, delta_t); debido a que para D2Q9 grad_Uz = 0

            

            s[id] = (chi/rho[id])*(grad_T[0]*grad_Rho[0]+grad_T[1]*grad_Rho[1]+grad_T[2]*grad_Rho[2]) + T[id]*(1-(1/(rho[id]*c_v)*(rho[id]*R/(1-rho[id]*b))))*(grad_Ux[0]+grad_Uy[1]+grad_Uz[2]);

        }
}