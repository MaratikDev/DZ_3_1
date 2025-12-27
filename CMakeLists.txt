cmake_minimum_required(VERSION 4.0)
project(dz3)

set(CMAKE_CXX_STANDARD 20)

add_executable(dz3 main.cpp
        IGraph.h
        ListGraph.cpp
        ListGraph.h
        MatrixGraph.cpp
        MatrixGraph.h
        SetGraph.cpp
        SetGraph.h
        ArcGraph.cpp
        ArcGraph.h)
