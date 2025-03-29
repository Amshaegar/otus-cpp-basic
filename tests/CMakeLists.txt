cmake_minimum_required (VERSION 3.11)

project(containers CXX)

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        v1.16.0
)
FetchContent_MakeAvailable(googletest)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

add_executable(containers_tests
    list_tests.cpp
    vector_tests.cpp
    main.cpp
)

target_include_directories(
    containers_tests PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/../src"
)

target_link_libraries(containers_tests PRIVATE gtest)

target_compile_features(containers_tests PUBLIC cxx_std_17)

if (MSVC)
    target_compile_options(containers_tests PUBLIC /W4 /WX)
else()
    target_compile_options(containers_tests PUBLIC -Wall -Wextra -Werror -pedantic)
endif()