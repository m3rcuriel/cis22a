cmake_minimum_required(VERSION 2.8.4)
project(Exercise_10)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES ex10.cpp)
add_executable(Exercise_10 ${SOURCE_FILES})