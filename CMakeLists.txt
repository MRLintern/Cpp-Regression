cmake_minimum_required(VERSION 3.16.3 FATAL_ERROR)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")


project(LinearGaussianRegression)

add_library(main_regression
    STATIC
        regression.hpp
        regression.cpp
)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/linear.txt
    DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/exponential.txt
    DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

add_executable(regression regression.cpp)

target_link_libraries(regression main_regression)
