cmake_minimum_required(VERSION 3.15)
project(ONP)

set(CMAKE_CXX_STANDARD 14)

add_executable(ONP main.cpp zmienna.cpp zmienna.hpp symbol.cpp symbol.hpp stala.cpp stala.hpp operand.cpp operand.hpp liczba.cpp liczba.hpp funkcja.cpp funkcja.hpp)