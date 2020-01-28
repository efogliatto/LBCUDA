#------------------ simpleReduction------------------#

# cudaSimpleReduction

add_executable(cudaSimpleReduction "cudaSimpleReduction.cu")

target_link_libraries(cudaSimpleReduction ${PROJECT_LINK_LIBS} ${PROJECT_LINK_LIBS})

set_property(TARGET cudaSimpleReduction PROPERTY CUDA_SEPARABLE_COMPILATION ON)
