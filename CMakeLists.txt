cmake_minimum_required(VERSION 3.3)
project(hw7 CXX)
include(.eecs230/CMakeLists.txt)

add_test_program(List_set_tests
        test/List_set_tests.cpp
        src/List_set.cpp
        src/List_set.h)
