cmake_minimum_required(VERSION 3.1)
add_definitions(-DLOCAL)
add_definitions(-ftrapv)
add_definitions(-D_GLIBCXX_DEBUG)
project(abc132)
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} -std=c++11)

add_executable(abc132_a a.cpp)
add_executable(abc132_b b.cpp)
add_executable(abc132_c c.cpp)
add_executable(abc132_d d.cpp)
add_executable(abc132_e e.cpp)
add_executable(abc132_f f.cpp)
