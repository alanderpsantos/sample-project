cmake_minimum_required(VERSION 3.22)

project(SampleProject C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_C_STANDARD 23)

add_subdirectory(modules/googletest)
add_subdirectory(doc)
add_subdirectory(lib)


enable_testing()
add_subdirectory(test)