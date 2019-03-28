cmake_minimum_required(VERSION 3.1)
add_definitions(-DLOCAL)project(abc088)
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} -std=c++11)

add_executable(abc088_a a.cpp)
add_executable(abc088_b b.cpp)
add_executable(abc088_c c.cpp)
add_executable(abc088_d d.cpp)
