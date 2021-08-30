cmake_minimum_required(VERSION 3.10)
project(mylang)

set(CMAKE_BUILD_TYPE Debug)
set (CMAKE_CXX_STANDARD 11)

file(GLOB SOURCES src/*.cc)
include_directories(include include/tree include/type 3rdparty/ 3rdparty/include)

add_executable(main ${SOURCES} main.cpp)
target_link_libraries(main ${CMAKE_SOURCE_DIR}/3rdparty/libs/libantlr3c.a)
