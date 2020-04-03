#------------------ Caracteristicas generales del proyecto ------------------#

cmake_minimum_required(VERSION 3.8 FATAL_ERROR)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake/Modules")

set(CMAKE_BUILD_TYPE Release)

set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/build)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)

set(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/lib)



# Bring the headers

include_directories(include)



# Compiler options for C

SET( CMAKE_C_FLAGS  "${CMAKE_C_FLAGS} -Wall -lm -pedantic -funroll-loops" )

if(CMAKE_BUILD_TYPE STREQUAL Debug)

  message("-- Compiling with debug options")

  SET( CMAKE_C_FLAGS  "${CMAKE_C_FLAGS} -g" )  
  
endif()



# Link libraries

set ( PROJECT_LINK_LIBS
  liblatticemodel.so
  liblatticemesh.so
  libbasic.so
  libd2q9.so
  liblbequation.so
  m
  )


set ( CUDATEST_LINK_LIBS
  cudatest.a
  cudalatticemesh.a
  cudalbequation.a
  )


link_directories( ${CMAKE_SOURCE_DIR}/lib )




# Opcional: Desabilitar CUDA para poder compilar al menos una parte en dispositivos sin GPU

option(DISABLE_CUDA "Deshabilitar manualmente la compilacion en CUDA" OFF)

if(DISABLE_CUDA)

  # Asignar solo C como lenguaje de compilacion
  
  project(LBCUDA_Test LANGUAGES C)
  
else()

  # Asignar C y CUDA como lenguajes
  
  project(LBCUDA_Test LANGUAGES CUDA C)


  # Bibliotecas para compilar CUDA

  find_package( CUDA REQUIRED )
  
  
  # Opciones de compilador

  SET( CMAKE_CUDA_FLAGS  "${CMAKE_CUDA_FLAGS} -gencode arch=compute_50,code=sm_50 -rdc=true" )    
  
endif()




# Optional: precision

set(PRECISION "simple" CACHE STRING "Floating-point precision")

if(PRECISION STREQUAL "double")

  message("-- C   : Double precision")

  add_definitions(-DDP)

  
  elseif(PRECISION STREQUAL "simple")

    add_definitions(-DSP)

    message("-- C   : Simple precision")

  else()

    message( FATAL_ERROR "Precision not supported" )
  
endif()





# Optional: CUDA precision

set(CUDA_PRECISION "simple" CACHE STRING "CUDA Floating-point precision")

if(CUDA_PRECISION STREQUAL "simple")

  message("-- CUDA: Simple precision")

  add_definitions(-DSP_CUDA)

  
  elseif(CUDA_PRECISION STREQUAL "double")

    add_definitions(-DDP_CUDA)

    message("-- CUDA: Double precision")

  else()

    message( FATAL_ERROR "CUDA Precision not supported" )
  
endif()




# Directorio con fuentes

add_subdirectory (src)


