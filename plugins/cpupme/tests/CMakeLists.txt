#
# Testing
#
ENABLE_TESTING()

SET(SHARED_OPENMM_PME_TARGET OpenMMPME)

IF (UNIX AND CMAKE_BUILD_TYPE MATCHES Debug)
    SET(SHARED_CUDA_TARGET ${SHARED_CUDA_TARGET}_d)
    SET(SHARED_OPENMM_PME_TARGET ${SHARED_OPENMM_PME_TARGET}_d)
ENDIF (UNIX AND CMAKE_BUILD_TYPE MATCHES Debug)

#LINK_DIRECTORIES

# Automatically create tests using files named "Test*.cpp"
FILE(GLOB TEST_PROGS "*Test*.cpp")
FOREACH(TEST_PROG ${TEST_PROGS})
    GET_FILENAME_COMPONENT(TEST_ROOT ${TEST_PROG} NAME_WE)

    # Link with shared library

    ADD_EXECUTABLE(${TEST_ROOT} ${TEST_PROG})
    TARGET_LINK_LIBRARIES(${TEST_ROOT} ${SHARED_TARGET} ${SHARED_OPENMM_TARGET} ${SHARED_OPENMM_PME_TARGET})
    ADD_TEST(${TEST_ROOT} ${EXECUTABLE_OUTPUT_PATH}/${TEST_ROOT})
ENDFOREACH(TEST_PROG ${TEST_PROGS})
