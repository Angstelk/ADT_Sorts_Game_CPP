cmake_minimum_required(VERSION 3.10)
project(V3)

set(CMAKE_CXX_STANDARD 11)

include_directories(.)

add_executable(V3
        AdjMatrix.cpp
        AdjMatrix.h
        Graph.cpp
        Graph.h
        List.cpp
        List.h
        MinHeap.cpp
        MinHeap.h
        MinHeapN.cpp
        MinHeapN.h
        PAMSI2.cpp)
