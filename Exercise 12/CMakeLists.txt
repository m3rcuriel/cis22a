cmake_minimum_required(VERSION 2.8.4)
project(Exercise_12)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES ex12.cpp)
add_executable(Exercise_12 ${SOURCE_FILES})