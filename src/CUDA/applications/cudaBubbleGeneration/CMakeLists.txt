#------------------ Generación de Burbuja ------------------#

# cudaBubbleGeneration

add_executable(cudaBubbleGeneration "cudaBubbleGeneration.cu" )

target_link_libraries(cudaBubbleGeneration ${PROJECT_LINK_LIBS} ${CUDATEST_LINK_LIBS})

set_property(TARGET cudaBubbleGeneration PROPERTY CUDA_SEPARABLE_COMPILATION ON)
