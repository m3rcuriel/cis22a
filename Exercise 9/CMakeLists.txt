cmake_minimum_required(VERSION 2.8.4)
project(Exercise_9)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES ex9.cpp)
add_executable(Exercise_9 ${SOURCE_FILES})