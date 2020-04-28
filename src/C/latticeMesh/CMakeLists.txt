#------------------ Generacion de bibliotecas ------------------#
 
# Lattice mesh library
add_library(latticemesh SHARED 
  writeBasicMesh.c
  readBasicMesh.c
  freeBasicMesh.c
  ../basic/int2dArray.c
  ../latticeModel/latticeVel.c
  ../latticeModel/MRT_invMatrix.c
  ../latticeModel/MRT_Matrix.c
  ../latticeModel/latticeCS2.c
  ../latticeModel/latticeReverseDir.c
  ../latticeModel/D2Q9/D2Q9_VelArray.c
  ../latticeModel/D2Q9/D2Q9_Reverse.c

  ../latticeModel/D2Q9/D2Q9_MRT_Matrix.c
  ../latticeModel/D2Q9/D2Q9_MRT_invMatrix.c

  )
