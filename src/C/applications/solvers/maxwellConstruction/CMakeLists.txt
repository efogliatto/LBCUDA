#------------------ Construccion de Maxwell------------------#


# Construccion de Maxwell

add_executable(maxwellConstruction "maxwellConstruction.c" "writeDebug.c")

target_link_libraries(maxwellConstruction ${PROJECT_LINK_LIBS} ${PROJECT_LINK_LIBS})
