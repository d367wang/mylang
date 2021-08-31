cmake_minimum_required(VERSION 3.10)
project(mylang)

set(CMAKE_BUILD_TYPE Debug)
set (CMAKE_CXX_STANDARD 14)

file(GLOB SOURCES src/*.cc src/tree/*.cc src/type/*.cc 3rdparty/*.c)
include_directories(include include/tree include/type include/base 3rdparty/ 3rdparty/include)

add_executable(main ${SOURCES} main.cpp)
target_link_libraries(main ${CMAKE_SOURCE_DIR}/3rdparty/libs/libantlr3c.a)
