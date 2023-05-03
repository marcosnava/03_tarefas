cmake_minimum_required(VERSION 3.24)
project(03_tarefas C)

set(CMAKE_C_STANDARD 11)

add_executable(03_tarefas main.c utils.h lista.h lista.c)
