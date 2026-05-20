cmake_minimum_required(VERSION 3.10)
project(hp-in-memory-data-engine)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED OFF)
set(CMAKE_CXX_EXTENSIONS OFF)   

#include_directories(include)
add_subdirectory(src)
add_subdirectory(tests)
