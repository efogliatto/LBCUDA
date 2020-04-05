#------------------ Generacion de bibliotecas ------------------#
 
# Input-output library
add_library(io SHARED
  writeMeshToEnsight.c
  writeScalarToEnsight.c
  writeVectorToEnsight.c
  updateCaseFile.c
  )
