cmake_minimum_required(VERSION 3.21)
project(06_PIPEX C)

set(CMAKE_C_STANDARD 99)

add_executable(06_PIPEX pipex.c pipex.h src_pipex/ft_error.c)
