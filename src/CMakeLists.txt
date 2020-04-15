# Bibliotecas y aplicaciones en C

add_subdirectory (C)



# Bibliotecas y aplicaciones en CUDA

if(DISABLE_CUDA MATCHES OFF)

  add_subdirectory (CUDA)
  
endif()



