#------------------ Generacion de bibliotecas ------------------#
 
# D2Q9 library
add_library(d2q9 SHARED 
  D2Q9_Vel.c
  D2Q9_VelArray.c
  D2Q9_Reverse.c
  D2Q9_MRT_Matrix.c
  D2Q9_MRT_invMatrix.c  
  )
