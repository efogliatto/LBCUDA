#include <fuerzaPsi.h>

#include <stdio.h>

#include <math.h>

//#include <stdio.h>


void fuerzaPsi(scalar* psi, scalar p_EOS, scalar rho, scalar c, scalar cs_2, scalar G) {

    // Calculo de psi
    
    *psi = pow ( fabs (( 2 * ( p_EOS - rho * cs_2 ) / ( G * c * c ) ) ), 0.5 );
 
}
