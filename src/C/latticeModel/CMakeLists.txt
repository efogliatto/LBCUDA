#------------------ Generacion de bibliotecas ------------------#
 
# LBMmodel library
add_library(latticemodel SHARED 
  latticeVelocities.c
  latticeVel.c
  latticeCS2.c
  latticeReverseDir.c
  MRT_Matrix.c
  MRT_invMatrix.c
  D2Q9/D2Q9_MRT_Matrix.c
  D2Q9/D2Q9_MRT_invMatrix.c
  D2Q9/D2Q9_VelArray.c
  D2Q9/D2Q9_Vel.c
  D2Q9/D2Q9_Reverse.c

  )


# D2Q9
add_subdirectory (D2Q9)


# # D3Q15
# add_subdirectory (D3Q15)
