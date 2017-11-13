cmake_minimum_required(VERSION 3.7)
project(Gradius)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp StopWatch.cpp StopWatch.h)
add_executable(Gradius ${SOURCE_FILES})