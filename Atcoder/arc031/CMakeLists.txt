cmake_minimum_required(VERSION 3.1)
add_definitions(-DLOCAL)
project(arc031)
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} -std=c++11)

add_executable(arc031_a a.cpp)
add_executable(arc031_b b.cpp)
add_executable(arc031_c c.cpp)
add_executable(arc031_d d.cpp)
