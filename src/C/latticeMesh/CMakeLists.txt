#------------------ Generacion de bibliotecas ------------------#
 
# Lattice mesh library
add_library(latticemesh SHARED 
  writeBasicMesh.c
  readBasicMesh.c
  freeBasicMesh.c
  )
