cmake_minimum_required(VERSION 3.1)

add_library(nicehash-api-cpp INTERFACE)
file(GLOB nicehash-api-cpp-sources
        ${CMAKE_SOURCE_DIR}/include/*.hpp
        ${CMAKE_SOURCE_DIR}/include/client/*.hpp
        ${CMAKE_SOURCE_DIR}/include/nicehash-api/*.hpp
        )
target_sources(nicehash-api-cpp INTERFACE ${nicehash-api-cpp-sources})
target_include_directories(nicehash-api-cpp INTERFACE include/)


#-------------------
# Tests
#-------------------

# Download and unpack googletest at configure time
configure_file(CMakeLists.txt.in googletest-download/CMakeLists.txt)
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
        ${CMAKE_BINARY_DIR}/googletest-build)

# The gtest/gtest_main targets carry header search path
# dependencies automatically when using CMake 2.8.11 or
# later. Otherwise we have to add them here ourselves.
if (CMAKE_VERSION VERSION_LESS 2.8.11)
    include_directories("${gtest_SOURCE_DIR}/include")
endif()

# Now simply link against gtest or gtest_main as needed. Eg
enable_testing()

file(GLOB test-src ${PROJECT_SOURCE_DIR}/test/*.test.cpp ${PROJECT_SOURCE_DIR}/test/nicehash-api/*.test.cpp)
add_executable(nicehash-api-cpp_test ${test-src})
target_link_libraries(nicehash-api-cpp_test gtest_main gmock_main nicehash-api-cpp)

add_test(NAME tests COMMAND nicehash-api-cpp_test)
