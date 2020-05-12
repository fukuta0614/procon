cmake_minimum_required(VERSION 3.1)
add_definitions(-DLOCAL)
add_definitions(-ftrapv)
add_definitions(-D_GLIBCXX_DEBUG)
project(abc020)
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} -std=c++14)

add_executable(abc020_d d.cpp)
