cmake_minimum_required (VERSION 3.8)

project (containers CXX)

add_executable(containers
    main.cpp
)

target_compile_features(containers PUBLIC cxx_std_17)

if (MSVC)
    target_compile_options(containers PUBLIC /W4 /WX)
else()
    target_compile_options(containers PUBLIC -Wall -Wextra -Werror -pedantic)
endif()
