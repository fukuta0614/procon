cmake_minimum_required(VERSION 3.1)
add_definitions(-DLOCAL)
add_definitions(-ftrapv)
add_definitions(-D_GLIBCXX_DEBUG)
project(abc091)
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} -std=c++11)

add_executable(abc091_a a.cpp)
add_executable(abc091_b b.cpp)
add_executable(abc091_c c.cpp)
add_executable(abc091_d d.cpp)
add_executable(abc091_e e.cpp)
add_executable(abc091_f f.cpp)
