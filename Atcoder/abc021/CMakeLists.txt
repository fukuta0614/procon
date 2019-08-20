cmake_minimum_required(VERSION 3.1)
add_definitions(-DLOCAL)
project(abc021)
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} -std=c++11)

add_executable(abc021_d d.cpp)
add_executable(abc021_d2 d2.cpp)
