cmake_minimum_required(VERSION 3.1)
add_definitions(-DLOCAL)
project(Keyence)
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} -std=c++11)

add_executable(Keyence_a a.cpp)
add_executable(Keyence_b b.cpp)
add_executable(Keyence_c c.cpp)
add_executable(Keyence_d d.cpp)
