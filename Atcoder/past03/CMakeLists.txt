cmake_minimum_required(VERSION 3.1)
add_definitions(-DLOCAL)
add_definitions(-ftrapv)
add_definitions(-D_GLIBCXX_DEBUG)
project(past03)
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} -std=c++11)

add_executable(past03_a a.cpp)
add_executable(past03_b b.cpp)
add_executable(past03_c c.cpp)
add_executable(past03_d d.cpp)
add_executable(past03_e e.cpp)
add_executable(past03_f f.cpp)
add_executable(past03_g g.cpp)
add_executable(past03_h h.cpp)
add_executable(past03_i i.cpp)
add_executable(past03_j j.cpp)
add_executable(past03_k k.cpp)
add_executable(past03_l l.cpp)
add_executable(past03_m m.cpp)
add_executable(past03_n n.cpp)
add_executable(past03_o o.cpp)
