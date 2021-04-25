cmake_minimum_required(VERSION 3.19)
project(c)

set(CMAKE_CXX_STANDARD 14)

add_executable(c main.cpp test.cpp)
add_executable(test test.cpp)
add_executable(time time.cpp)
add_executable(struct struct.cpp)
add_executable(calss_test cmake-build-debug/calss_test.cpp)