#include <fuerzaPresionEOS.h>

#include <stdio.h>

void fuerzaPresionEOS(scalar* p_EOS, scalar rho, scalar T, int a, int b) {

    // Constante universal de los gases (preguntar en que unidades se debe colocar ya que este modelo es adimensional)

	scalar R = 1; 


    // Calculo de la presion

	*p_EOS = ( ( rho * R * T ) / ( 1 - rho * b ) ) - ( a * rho * rho ) ;	    

//	printf( "\n  p_EOS: %f \t \n", *p_EOS);
   

}
