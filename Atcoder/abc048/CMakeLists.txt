cmake_minimum_required(VERSION 3.1)
add_definitions(-DLOCAL)
add_definitions(-ftrapv)
add_definitions(-D_GLIBCXX_DEBUG)
project(abc048)
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} -std=c++11)

add_executable(abc048_a a.cpp)
add_executable(abc048_b b.cpp)
add_executable(abc048_c c.cpp)
add_executable(abc048_d d.cpp)
add_executable(abc048_e e.cpp)
add_executable(abc048_f f.cpp)
