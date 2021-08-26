cmake_minimum_required(VERSION 3.10)
project(echo)

set(CMAKE_BUILD_TYPE Debug)

file(GLOB SOURCES src/*.cpp)
include_directories(include 3rdparty/ 3rdparty/include)

add_executable(main ${SOURCES} main.cpp)
target_link_libraries(main 3rdparty/libs/*.a)
