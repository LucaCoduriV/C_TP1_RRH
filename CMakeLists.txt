cmake_minimum_required(VERSION 3.17)
project(C_TP1_RRH C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wconversion -Wsign-conversion -pedantic")

add_executable(C_TP1_RRH main.c listes_dynamiques.h listes_dynamiques.c programmeTest.c programmeTest.h)