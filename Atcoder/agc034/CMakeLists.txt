cmake_minimum_required(VERSION 3.1)
add_definitions(-DLOCAL)
project(agc034)
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} -std=c++11)

add_executable(agc034_a a.cpp)
add_executable(agc034_b b.cpp)
add_executable(agc034_c c.cpp)
add_executable(agc034_d d.cpp)
add_executable(agc034_e e.cpp)
add_executable(agc034_f f.cpp)
