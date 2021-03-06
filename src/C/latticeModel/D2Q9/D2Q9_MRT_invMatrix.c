#include <D2Q9_MRT_invMatrix.h>

#include <stdlib.h>

scalar* D2Q9_MRT_invMatrix() {

    scalar* M;
  
    M = (scalar*)malloc( 81 * sizeof(scalar));

    scalar c1 = 1.0 / 9.0,
	   c2 = 1.0 / 6.0,
	   c3 = 1.0 / 4.0;    


    M[0] =  c1; 
    M[1] = -c1; 
    M[2] =  c1; 
    M[3] =   0; 
    M[4] =   0; 
    M[5] =   0; 
    M[6] =   0; 
    M[7] =   0; 
    M[8] =   0; 
    
    M[9]  =    c1; 
    M[10] = -c1/4; 
    M[11] = -c1/2; 
    M[12] =    c2; 
    M[13] =   -c2; 
    M[14] =     0; 
    M[15] =     0; 
    M[16] =    c3; 
    M[17] =     0; 
    
    M[18] =    c1;
    M[19] = -c1/4;
    M[20] = -c1/2;
    M[21] =     0;
    M[22] =     0;
    M[23] =    c2;
    M[24] =   -c2;
    M[25] =   -c3;
    M[26] =     0;
    
    M[27] =    c1; 
    M[28] = -c1/4; 
    M[29] = -c1/2; 
    M[30] =   -c2; 
    M[31] =    c2; 
    M[32] =     0; 
    M[33] =     0; 
    M[34] =    c3; 
    M[35] =     0; 
    
    M[36] =    c1; 
    M[37] = -c1/4; 
    M[38] = -c1/2; 
    M[39] =     0; 
    M[40] =     0; 
    M[41] =   -c2; 
    M[42] =    c2; 
    M[43] =   -c3; 
    M[44] =     0; 
    
    M[45] =    c1; 
    M[46] =  c1/2; 
    M[47] =  c1/4; 
    M[48] =    c2; 
    M[49] =  c2/2; 
    M[50] =    c2; 
    M[51] =  c2/2; 
    M[52] =     0; 
    M[53] =    c3; 
    
    M[54] =    c1; 
    M[55] =  c1/2; 
    M[56] =  c1/4; 
    M[57] =   -c2; 
    M[58] = -c2/2; 
    M[59] =    c2; 
    M[60] =  c2/2; 
    M[61] =     0; 
    M[62] =   -c3; 
    
    M[63] =    c1; 
    M[64] =  c1/2; 
    M[65] =  c1/4; 
    M[66] =   -c2; 
    M[67] = -c2/2; 
    M[68] =   -c2; 
    M[69] = -c2/2; 
    M[70] =     0; 
    M[71] =    c3; 
    
    M[72] =    c1; 
    M[73] =  c1/2; 
    M[74] =  c1/4; 
    M[75] =    c2; 
    M[76] =  c2/2; 
    M[77] =   -c2; 
    M[78] = -c2/2; 
    M[79] =     0; 
    M[80] =   -c3; 
    

    return M;

}
