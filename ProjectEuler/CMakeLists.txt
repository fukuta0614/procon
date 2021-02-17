cmake_minimum_required(VERSION 3.1)
add_definitions(-DLOCAL)
#add_definitions(-ftrapv)
#add_definitions(-D_GLIBCXX_DEBUG)

include_directories(../Library/ac-library)

project(ProjectEuler)
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-Wall -fsanitize=undefined -std=c++17")

add_executable(ProjectEuler_test test.cpp)
add_executable(ProjectEuler_001 001.cpp)
add_executable(ProjectEuler_101 101.cpp)
add_executable(ProjectEuler_201 201.cpp)
add_executable(ProjectEuler_301 301.cpp)
add_executable(ProjectEuler_401 401.cpp)
add_executable(ProjectEuler_501 501.cpp)
