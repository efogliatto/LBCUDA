#------------------ Generacion de bibliotecas ------------------#
 
# Esquemas LB
add_library(lbequation SHARED 
  exampleModel/exampleCollision.c
  exampleModel/exampleDensity.c
  exampleModel/exampleVelocity.c 

  momentoFunciondist/momentoCollision.c
  momentoFunciondist/momentoDensity.c
  momentoFunciondist/momentoVelocity.c
  momentoFunciondist/momentoFeq.c 

  fuerza/fuerzaPresionEOS.c
  fuerza/fuerzaPsi.c
  fuerza/fuerzaFuerzaint.c
  fuerza/fuerzaFuerzatotal.c
  fuerza/fuerzaS.c
    
  streaming/streamingUpdate.c
  streaming/streamingNbReduction.c
  streaming/lbstreaming.c

  energy/energyCollision.c
  energy/energyGradient.c
  energy/energyGradientU.c
  energy/energyS.c
  energy/energyTemp.c
  energy/energyEqDistMomento.c
  energy/energyEqDistNode.c
  energy/fixedTBoundary.c
  
  )
