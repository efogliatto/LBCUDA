#------------------ Generacion de bibliotecas ------------------#
 
# Basic library. Simple operations
add_library(basic SHARED 
  int2dArray.c
  scalar2dArray.c
  timeOptions.c
  zerothMomentCPU.c
  nbReductionCPU.c
  readInitialParameters.c
  writeTime.c
  )
