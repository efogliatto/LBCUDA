#------------------ collisionC------------------#


# collisionC

add_executable(maxwellConstruction "maxwellConstruction.c" "writeDebugMC.c")

target_link_libraries(maxwellConstruction ${PROJECT_LINK_LIBS} ${PROJECT_LINK_LIBS})