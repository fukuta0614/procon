cmake_minimum_required(VERSION 3.1)
add_definitions(-DLOCAL)
project(test)
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} -std=c++11)

add_executable(test_c c.cpp)
