cmake_minimum_required (VERSION 3.8)
project(calculator)


set(BIN_NAME calculator)
set(LIB_NAME calcLib)


file(
    GLOB SRC_FILES
    main.cpp
)

file(
    GLOB LIB_FILES
    calculator.cpp
    calculator.h
)



add_executable(${BIN_NAME} ${SRC_FILES})

add_library(${LIB_NAME} STATIC ${LIB_FILES})

target_link_libraries(${BIN_NAME} ${LIB_NAME})
