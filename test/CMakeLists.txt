# Download and unpack googletest at configure time
configure_file(External_GTest.cmake ${CMAKE_BINARY_DIR}/googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
        RESULT_VARIABLE result
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download )
if(result)
    message(FATAL_ERROR "CMake step for googletest failed: ${result}")
endif()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
        RESULT_VARIABLE result
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download )
if(result)
    message(FATAL_ERROR "Build step for googletest failed: ${result}")
endif()

# Prevent overriding the parent project's compiler/linker
# settings on Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Add googletest directly to our build. This defines
# the gtest and gtest_main targets.
add_subdirectory(${CMAKE_BINARY_DIR}/googletest-src
        ${CMAKE_BINARY_DIR}/googletest-build
        EXCLUDE_FROM_ALL)


include(GoogleTest)
add_executable(Test
        src/main.cc
        src/pixels_test.cc
        src/vector_pipeline_test.cc
        src/loop_pipeline_test.cc
        src/scale_stage_test.cc)
target_include_directories(Test
        PRIVATE
        include
        ${CMAKE_BINARY_DIR}/include
        ${CMAKE_BINARY_DIR}/googletest-src/googletest/include
        ${CMAKE_BINARY_DIR}/googletest-src/googlemock/include)
target_link_libraries(Test colorpipe gtest_main gmock_main)
target_compile_features(Test
        PUBLIC
        cxx_std_14
        )

gtest_discover_tests(Test)
