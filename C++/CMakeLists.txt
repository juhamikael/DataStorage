cmake_minimum_required(VERSION 3.21)
project(DataStorage_Cpp)

set(CMAKE_CXX_STANDARD 14)

add_executable(
        DataStorage_Cpp
        main.cpp
        Food.cpp
        Food.h
        Funcs.cpp
        Funcs.h
        FoodSingleton.cpp
        FoodSingleton.h)
