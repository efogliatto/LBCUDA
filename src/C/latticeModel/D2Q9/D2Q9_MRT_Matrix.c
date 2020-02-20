#include <D2Q9_MRT_Matrix.h>

#include <stdlib.h>

scalar* D2Q9_MRT_Matrix() {

    scalar* M;
  
    M = (scalar*)malloc( 81 * sizeof(scalar));


    M[0] = 1;
    M[1] = 1;
    M[2] = 1;
    M[3] = 1;
    M[4] = 1;
    M[5] = 1;
    M[6] = 1;
    M[7] = 1;
    M[8] = 1;
    
    M[9]  = -4; 
    M[10] = -1; 
    M[11] = -1; 
    M[12] = -1; 
    M[13] = -1; 
    M[14] = 2; 
    M[15] = 2; 
    M[16] = 2; 
    M[17] = 2; 
    
    M[18] =  4;
    M[19] = -2;
    M[20] = -2;
    M[21] = -2;
    M[22] = -2;
    M[23] =  1;
    M[24] =  1;
    M[25] =  1;
    M[26] =  1;
    
    M[27] =  0; 
    M[28] =  1; 
    M[29] =  0; 
    M[30] = -1; 
    M[31] =  0; 
    M[32] =  1; 
    M[33] = -1; 
    M[34] = -1; 
    M[35] =  1; 
    
    M[36] =  0; 
    M[37] = -2; 
    M[38] =  0; 
    M[39] =  2; 
    M[40] =  0; 
    M[41] =  1; 
    M[42] = -1; 
    M[43] = -1; 
    M[44] =  1; 
    
    M[45] =  0; 
    M[46] =  0; 
    M[47] =  1; 
    M[48] =  0; 
    M[49] = -1; 
    M[50] =  1; 
    M[51] =  1; 
    M[52] = -1; 
    M[53] = -1; 
    
    M[54] =  0; 
    M[55] =  0; 
    M[56] = -2; 
    M[57] =  0; 
    M[58] =  2; 
    M[59] =  1; 
    M[60] =  1; 
    M[61] = -1; 
    M[62] = -1; 
    
    M[63] =  0; 
    M[64] =  1; 
    M[65] = -1; 
    M[66] =  1; 
    M[67] = -1; 
    M[68] =  0; 
    M[69] =  0; 
    M[70] =  0; 
    M[71] =  0; 
    
    M[72] =  0; 
    M[73] =  0; 
    M[74] =  0; 
    M[75] =  0; 
    M[76] =  0; 
    M[77] =  1; 
    M[78] = -1; 
    M[79] =  1; 
    M[80] = -1; 
    

    return M;

}