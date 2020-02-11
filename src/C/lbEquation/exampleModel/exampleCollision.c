#include <exampleCollision.h>

#include <stdlib.h>


void exampleCollision( basicMesh* mesh, scalar* field, scalar* rho, scalar* U) {


    
    // Partial distributions
    
    scalar* m     = (scalar*)malloc( mesh->Q * sizeof(scalar) );   // m:  momentum space
    
    scalar* m_eq  = (scalar*)malloc( mesh->Q * sizeof(scalar) );   // meq: equilibrium in momentum space

    scalar* S     = (scalar*)malloc( mesh->Q * sizeof(scalar) );   // MRT force



    
    // Colision sobre todos los nodos
    
    for( uint id = 0 ; id < mesh->nPoints ; id++ ) {
	


	// Magnitud de la velocidad
	
	scalar umag = 0;
	
	for( uint k = 0 ; k < 3 ; k++ )	
	    umag += U[id*3 + k] * U[id*3 + k];


	
	// Compute equilibrium in momentum space
	
	m_eq[0] = rho[id];
	m_eq[1] = rho[id] * (-2 + 3*umag);
	m_eq[2] = rho[id] * (1 - 3*umag);
	m_eq[3] = rho[id] * U[id*3];
	m_eq[4] = rho[id] * (-U[id*3]);
	m_eq[5] = rho[id] * U[id*3+1];
	m_eq[6] = rho[id] * (-U[id*3+1]);
	m_eq[7] = rho[id] * (U[id*3]*U[id*3] - U[id*3+1]*U[id*3+1]);
	m_eq[8] = rho[id] * U[id*3] * U[id*3+1];

	
	/* // Distribution in momentum space */

	/* matVecMult(mesh->lattice.M, field->value[id], m, mesh->lattice.Q); */


	
	/* // Total Force */
	
	/* liMRTForce( mesh, mfields, field, S, id ); */


       

	
	/* // Collision in momentum space */
	
	/* for( k = 0 ; k < mesh->lattice.Q ; k++ ) { */

	/*     m[k] = m[k]  -  field->lbparam.liMRT.Lambda[k]*( m[k] - m_eq[k] )  +  ( 1 - 0.5*field->lbparam.liMRT.Lambda[k] ) * S[k]; */

	/*     if(field->lbparam.liMRT.surfaceTension == liSurfTen) { */

	/*     	m[k] = m[k] + C[k]; */

	/*     } */
	    
	/* } */

	
	
	/* // Back to phase space */
	
	/* matVecMult(mesh->lattice.invM, m, field->value[id], mesh->lattice.Q); */

	
    }


    // Deallocate memory

    free(m);
    
    free(m_eq);

    free(S);


}
