cmake_minimum_required(VERSION 3.5)

project(GuessTheNumber)

add_executable(gtn
    handle_parameters.h
    handle_parameters.cpp    
    high_scores.h
    high_scores.cpp
    main.cpp
)