cmake_minimum_required(VERSION 3.1)
add_definitions(-DLOCAL)
add_definitions(-ftrapv)
add_definitions(-D_GLIBCXX_DEBUG)
project(abc164)
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} -std=c++11)

add_executable(abc164_a a.cpp)
add_executable(abc164_b b.cpp)
add_executable(abc164_c c.cpp)
add_executable(abc164_d d.cpp)
add_executable(abc164_e e.cpp)
add_executable(abc164_f f.cpp)
