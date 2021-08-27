cmake_minimum_required(VERSION 3.19)
project(Tarea1Datos)

set(CMAKE_CXX_STANDARD 14)

set(Headers PagedArray.h QuickSort.h HashTable.h)

add_executable(Tarea1Datos main.cpp PagedArray.cpp QuickSort.cpp HashTable.cpp)