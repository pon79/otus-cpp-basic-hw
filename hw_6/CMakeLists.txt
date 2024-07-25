cmake_minimum_required(VERSION 3.25)

add_executable(my_container
    main.cpp
    sequentialcontainer.h sequentialcontainer.cpp
)

set_target_properties(my_container PROPERTIES
    CXX_STANDARD 20
    CXX_STANDARD_REQUIRED ON
)

