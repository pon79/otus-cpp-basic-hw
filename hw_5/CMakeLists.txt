cmake_minimum_required(VERSION 3.25)

add_executable(statistics statistics.cpp
    istatistics.h
    min.h min.cpp
    max.h max.cpp
    mean.h mean.cpp
    stddeviation.h stddeviation.cpp
)

set_target_properties(statistics PROPERTIES
    CXX_STANDARD 20
    CXX_STANDARD_REQUIRED ON
)

