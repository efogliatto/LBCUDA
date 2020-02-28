#include <fuerzaPsi.h>

#include <stdio.h>

#include <math.h>


void fuerzaPsi(scalar psi, scalar p_EOS, scalar rho, scalar c, scalar cs_2, scalar G) {

    // Calculo de psi
    
	psi = pow ( ( 2 * ( p_EOS - rho * cs_2 ) / ( G * c * c ) ), 0.5 );

 
}
