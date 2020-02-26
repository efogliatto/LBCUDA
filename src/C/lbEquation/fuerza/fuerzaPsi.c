#include <fuerzaPsi.h>

#include <fuerzaPresionEOS.h>

#include <stdio.h>

#include <math.h>


void fuerzaPsi(scalar* psi, scalar* p_EOS, scalar* rho, scalar c, scalar cs_2, scalar G, basicMesh* mesh) {


    // Suma de todas las componentes
    
    for( uint i = 0 ; i <  mesh->nPoints  ; i++ ) {

	psi[i] = pow ( ( 2 * ( p_EOS[i] - rho[i] * cs_2 ) / ( G * c * c ) ), 0.5 );

   }
    

}
