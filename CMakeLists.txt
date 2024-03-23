cmake_minimum_required(VERSION 3.27)
project(MOLR)

set(CMAKE_CXX_STANDARD 17)

add_executable(MOLR src/main.cpp include/config.h
        include/OneDimensional.h
        src/OneDimensional.cpp
        src/MultiDimensional.cpp
        include/MultiDimensional.h)

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -D_DEBUG")