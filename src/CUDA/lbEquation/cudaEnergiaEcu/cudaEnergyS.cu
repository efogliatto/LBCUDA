#include <cudaEnergyS.h>

#include <cudaEnergy.h>

#include <cudaEnergyGradient.h>

#include <cudaEnergyGradientU.h>

#include <stdlib.h>

#include <stdio.h>

extern "C" __global__ void cudaEnergyS( cuscalar* s, cuscalar* rho, cuscalar* T, cuscalar* U, cudaEnergyCoeffs* relax, cuscalar* field, cuscalar alpha_1, cuscalar alpha_2,  cuscalar cs_2, cuscalar delta_t, cuscalar c_v, cuscalar b, unit np, int Q, int* lvel,int* nb, cuscalar* Tau) {

    int id = threadIdx.x + blockIdx.x*blockDim.x;

        cuscalar chi = delta_t * ( ( 1 / Tau[2]) -0.5 ) * ( (4 + 3 *alha_1 +2 * alpha_2 ) / 6.0 );
        
        cuscalar grad_Rho[3];
        cuscalar grad_T[3];
        cuscalar grad_Ux[3];
        cuscalar grad_Uy[3];
        cuscalar grad_Uz[3]={0,0,0};


        if( id > np ){

            cuscalar auxField[9] = {0,0,0,0,0,0,0,0,0};
		    
		    // Copia de parametros auxiliares para el calculo de S
            uint k = 0 ;			    
		    
            while( k < 9 )	{
					
			    auxField[k] = field[id*9 + k];

                k++;
		    }
            
            cudaEnergyGradient( grad_T, auxField, T, id, cs_2, delta_t, Q, lvel, nb);
            cudaEnergyGradient( grad_Rho, auxField, rho, id, cs_2, delta_t, Q, lvel, nb);
            cudaEnergyGradientU( grad_Ux, auxField, 0, U, id, cs_2, delta_t, Q, lvel, nb);
            cudaEnergyGradientU( grad_Uy, auxField, 1, U, id, cs_2, delta_t, Q, lvel, nb);
            //cudaEnergyGradientU( grad_Uz, auxField, 2, U, id, cs_2, delta_t, Q, lvel, nb); debido a que para D2Q9 grad_Uz = 0

            s[id] = (chi/rho[id])*(grad_T[0]*grad_Rho[0]+grad_T[1]*grad_Rho[1]+grad_T[2]*grad_Rho[2]) + T[id]*(1-(1/(rho[id]*c_v)*(rho[id]*R/(1-rho[id]*b))))*(grad_Ux[0]+grad_Uy[1]+grad_Uz[2]);

        }
}

