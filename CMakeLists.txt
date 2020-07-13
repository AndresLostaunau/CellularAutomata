cmake_minimum_required(VERSION 3.14)
project(CellularAutomata)

set(CMAKE_CXX_STANDARD 14)

add_executable(CellularAutomata
        GameOfLife.cpp
        main.cpp)
