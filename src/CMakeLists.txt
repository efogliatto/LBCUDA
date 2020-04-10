# Bibliotecas y aplicaciones en C
add_subdirectory (C)


# Bibliotecas y aplicaciones en CUDA

if(DISABLE_CUDA EQUAL OFF)

  message("-- Compiling with CUDASS")
  message("-- Compiling with CUDASS")
  message("-- Compiling with CUDASS")

  add_subdirectory (CUDA)
  
endif()



