cmake_minimum_required(VERSION 3.1)
project(abc106)
add_definitions(-DLOCAL)

set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} -std=c++11)
add_executable(abc106_a a.cpp)
add_executable(abc106_b b.cpp)
add_executable(abc106_c c.cpp)
add_executable(abc106_d d.cpp)
