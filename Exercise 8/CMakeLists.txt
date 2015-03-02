cmake_minimum_required(VERSION 2.8.4)
project(Exercise_8)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES ex8.cpp)
add_executable(Exercise_8 ${SOURCE_FILES})