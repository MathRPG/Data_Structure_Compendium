cmake_minimum_required(VERSION 3.17)
project(Data_Structures C)

set(CMAKE_C_STANDARD 11)

include_directories(include)

add_executable(Data_Structures main.c)
add_executable(Data_Structure_Tests include/testing.h tests/test_dynamic_stack.c src/dynamic_stack.c)
