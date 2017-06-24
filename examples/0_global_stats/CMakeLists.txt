set (CMAKE_CXX_STANDARD 11)
cmake_minimum_required(VERSION 3.1)

include(ExternalProject)
ExternalProject_Add(nicehash-api-cpp
  GIT_REPOSITORY    https://github.com/4iar/nicehash-api-cpp.git
  GIT_TAG           master
  SOURCE_DIR        "${CMAKE_BINARY_DIR}/nicehash-src"
  BINARY_DIR        "${CMAKE_BINARY_DIR}/nicehash-build"
)

include_directories(${CMAKE_BINARY_DIR}/nicehash-src/include)

add_executable(main main.cpp)
add_dependencies(main nicehash-api-cpp)
target_link_libraries(main ${CMAKE_BINARY_DIR}/nicehash-build/libnicehash-api-cpp.so)
