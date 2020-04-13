#------------------ Generacion de bibliotecas ------------------#
 
# Operadores diferenciales
add_library(fdoperations SHARED 
  scalarGradient.c
  # scalarLaplacian.c
  vectorDivergence.c
  )
