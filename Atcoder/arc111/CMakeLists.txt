cmake_minimum_required(VERSION 3.1)
add_definitions(-DLOCAL)
add_definitions(-ftrapv)
add_definitions(-D_GLIBCXX_DEBUG)
project(arc111)
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} -std=c++14)

add_executable(arc111_a a.cpp)
add_executable(arc111_b b.cpp)
add_executable(arc111_c c.cpp)
add_executable(arc111_d d.cpp)
add_executable(arc111_e e.cpp)
add_executable(arc111_f f.cpp)
