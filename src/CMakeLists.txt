cmake_minimum_required(VERSION 3.2)
project(hapicpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(SOURCE_FILES main.cpp)

find_library(restclient-cpp NAMES restclient restclient-cpp)

add_executable(hapicpp ${SOURCE_FILES})

target_link_libraries(hapicpp restclient-cpp)
