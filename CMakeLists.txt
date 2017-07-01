set (CMAKE_CXX_STANDARD 11)
cmake_minimum_required(VERSION 3.1)

file(GLOB nicehash-api-cpp-sources
        ${PROJECT_SOURCE_DIR}/src/client/*.cpp
        ${PROJECT_SOURCE_DIR}/src/nicehash-api/*.cpp
        )
add_library(nicehash-api-cpp SHARED ${nicehash-api-cpp-sources})
target_sources(nicehash-api-cpp PUBLIC ${nicehash-api-cpp-sources})
target_include_directories(nicehash-api-cpp PUBLIC ${PROJECT_SOURCE_DIR}/include)

find_package(CURL REQUIRED)
include_directories(${CURL_INCLUDE_DIRS})

target_link_libraries(nicehash-api-cpp ${CURL_LIBRARIES})


#-------------------
# Tests
#-------------------

# Download and unpack googletest at configure time
configure_file(cmake/external.txt.in googletest-download/CMakeLists.txt)
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

enable_testing()

file(GLOB test-src ${PROJECT_SOURCE_DIR}/test/*.test.cpp ${PROJECT_SOURCE_DIR}/test/nicehash-api/*.test.cpp)
add_executable(nicehash-api-cpp_test ${test-src})
target_link_libraries(nicehash-api-cpp_test gtest_main gmock_main gmock nicehash-api-cpp)

add_test(NAME tests COMMAND nicehash-api-cpp_test)

#-------------------
# Docs
#-------------------

# add a target to generate API documentation with Doxygen
find_package(Doxygen)
if(DOXYGEN_FOUND)
    configure_file(${CMAKE_CURRENT_SOURCE_DIR}/doc/Doxyfile.in ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile @ONLY)
    add_custom_target(doc
            ${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile
            WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
            COMMENT "Generating API documentation with Doxygen" VERBATIM
            )
endif(DOXYGEN_FOUND)
