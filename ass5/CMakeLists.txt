cmake_minimum_required(VERSION 2.8.4)
project(ass5)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES ass5.cpp player.cpp player.hpp)
add_executable(ass5 ${SOURCE_FILES})