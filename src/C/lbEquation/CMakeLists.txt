#------------------ Generacion de bibliotecas ------------------#
 
# Esquemas LB
add_library(lbequation SHARED 
  exampleModel/exampleCollision.c
  exampleModel/exampleDensity.c
  exampleModel/exampleVelocity.c 

  momentoFunciondist/momentoCollision.c
  momentoFunciondist/momentoDensity.c
  momentoFunciondist/momentoVelocity.c  
  )
