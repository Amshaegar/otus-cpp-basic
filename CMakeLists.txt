cmake_minimum_required(VERSION 3.5)

project(statistics)

add_executable(statistics
    main.cpp
    Min.cpp
    Max.cpp
    Mean.cpp
    StandartDeviation.cpp)
set_target_properties(statistics PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)
