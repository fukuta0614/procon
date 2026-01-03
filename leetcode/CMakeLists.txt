cmake_minimum_required(VERSION 3.0)
project(tdpc)
add_definitions(-DLOCAL)
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} -std=c++11)

add_executable(test 30_Substring_with_Concatenation_of_All_Words.cpp)
