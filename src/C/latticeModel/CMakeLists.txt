#------------------ Generacion de bibliotecas ------------------#
 
# LBMmodel library
add_library(latticemodel SHARED 
  latticeVelocities.c
  latticeVel.c
  latticeReverseDir.c
  MRT_Matrix.c
  MRT_invMatrix.c
  )


# D2Q9
add_subdirectory (D2Q9)


# # D3Q15
# add_subdirectory (D3Q15)
