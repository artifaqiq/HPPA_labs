cmake_minimum_required(VERSION 3.6)
project(1)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-msse")

set(SOURCE_FILES_1 1.cpp)
add_executable(auto ${SOURCE_FILES_1})

set(SOURCE_FILES_2 2.cpp)
add_executable(manual ${SOURCE_FILES_2})