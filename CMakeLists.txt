cmake_minimum_required(VERSION 3.22)
project(CP8 C)

set(CMAKE_C_STANDARD 99)

add_executable(CP8 main.c list_item.c list_item.h iterator.h list.c list.h)
