cmake_minimum_required(VERSION 3.5)
project(lab3)

set(BINARY lab3)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

file(
        GLOB SOURCES
        *.cpp
)

file(
        GLOB HEADERS
        *.h
)

add_executable(${BINARY} ${SOURCES} ${HEADERS})
