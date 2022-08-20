cmake_minimum_required(VERSION 3.5)

project(rollenspiel_operatorueberladen LANGUAGES CXX)

add_library(rollenspiel STATIC rollenspiel.cpp rollenspiel.h)

find_library(TEST_LIBRARY librollenspiel.a lib)

target_link_libraries(rollenspiel LINK_PUBLIC ${TEST_LIBRARY})

add_executable(rollenspielgame rollenspiel.h main.cpp)