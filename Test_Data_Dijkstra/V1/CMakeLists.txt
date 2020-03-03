cmake_minimum_required(VERSION 3.10)
project(V1)

set(CMAKE_CXX_STANDARD 11)

include_directories(.)
include_directories(list)
include_directories(matrix)
include_directories(priority_queue)

add_executable(V1
        list/dlist.hpp
        list/slist.hpp
        matrix/matrix.hpp
        priority_queue/priority_queue.hpp
        priority_queue/priority_queue2.hpp
        Graph_AdjList.hpp
        Graph_AdjMatrix.hpp
        pair.hpp
        PAMSI_03.cpp)
