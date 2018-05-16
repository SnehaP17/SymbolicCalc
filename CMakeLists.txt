cmake_minimum_required(VERSION 3.9)
project(calculatorTwo)

set(CMAKE_CXX_STANDARD 11)

add_executable(calculatorTwo main.cpp addition.cpp addition.h multiplication.cpp multiplication.h subtraction.cpp subtraction.h division.cpp division.h exponent.cpp exponent.h calculate.cpp calculate.h)