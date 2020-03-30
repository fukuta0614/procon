cmake_minimum_required(VERSION 3.1)
project(pico_overflow_1)
#set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} -std=c++11)

add_executable(pico_overflow_1 vuln.c)
