cmake_minimum_required(VERSION 3.17)
project(Data_Structures C)

set(CMAKE_C_STANDARD 11)

include_directories(include)

add_executable(Main main.c)
add_executable(Stack_Tests include/testing.h tests/test_dynamic_stack.c src/dynamic_stack.c src/node.c)
add_executable(Vector_Tests tests/test_vector.c)
