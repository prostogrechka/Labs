cmake_minimum_required(VERSION 3.16.3)

project("Labs")

add_library(calculatorLib STATIC calculator.cpp calculator.h)
add_executable(2 main.cpp)
target_link_libraries(2 calculatorLib)
