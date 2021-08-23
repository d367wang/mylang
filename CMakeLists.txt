cmake_minimum_required(VERSION 3.10)
project(echo)

set(CMAKE_BUILD_TYPE Debug)

file(GLOB SOURCES src/*.cpp)
include_directories(include parser/ parser/include)
target_link_libraries(main parser/libs/*.a)

add_executable(main ${SOURCES} main.cpp)