cmake_minimum_required(VERSION 3.9...3.19)
project(Ex20 CXX)

# require a C++11 compiler for all targets
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# build tests
add_executable(unit_tests catch.hpp unit_tests.cpp
  abstract_list.hpp
  array_list.hpp array_list.tpp
  linked_list.hpp linked_list.tpp
  test_algorithms.cpp)