cmake_minimum_required(VERSION 3.1)
add_definitions(-DLOCAL)
add_definitions(-ftrapv)
add_definitions(-D_GLIBCXX_DEBUG)
project(abc090)
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-Wall -std=c++17")

add_executable(abc090_a a.cpp)
add_executable(abc090_b b.cpp)
add_executable(abc090_c c.cpp)
add_executable(abc090_d d.cpp)
add_executable(abc090_e e.cpp)
add_executable(abc090_f f.cpp)
