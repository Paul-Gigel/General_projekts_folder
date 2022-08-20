cmake_minimum_required(VERSION 3.5)

project(buildingLibrary LANGUAGES CXX)

add_library(calc STATIC calc.cpp)

add_executable(main mylib.h main.cpp)

find_library(TEST_LIBRARY libcalc.a lib)

target_link_libraries(main LINK_PUBLIC ${TEST_LIBRARY})
