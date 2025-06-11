cmake_minimum_required (VERSION 3.8)

project (topk_words CXX)

add_executable(topk_words
    topk_words.cpp
)

target_compile_features(topk_words PUBLIC cxx_std_17)

if (MSVC)
    target_compile_options(topk_words PUBLIC /W4 /WX)
else()
    target_compile_options(topk_words PUBLIC -Wall -Wextra -Werror -pedantic)
endif()
