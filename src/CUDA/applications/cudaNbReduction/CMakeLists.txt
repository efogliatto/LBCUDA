#------------------ cudaNbReduction------------------#

# cudaNbReduction

add_executable(cudaNbReduction "cudaNbReduction.cu")

target_link_libraries(cudaNbReduction ${PROJECT_LINK_LIBS} ${CUDATEST_LINK_LIBS} ${PROJECT_LINK_LIBS} ${CUDATEST_LINK_LIBS})

set_property(TARGET cudaNbReduction PROPERTY CUDA_SEPARABLE_COMPILATION ON)
