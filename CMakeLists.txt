cmake_minimum_required(VERSION 3.1)

project(ausrv)

include_directories(include)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror")

add_executable(prog_02170392_521 src/main.cpp src/tinyxml2.cpp src/reader.cpp src/analyzer.cpp)
