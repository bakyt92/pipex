cmake_minimum_required(VERSION 3.20)
project(06_PIPEX C)

set(CMAKE_C_STANDARD 99)

add_executable(06_PIPEX pipex.c pipex.h src_pipex/ft_error.c src_pipex/ft_utils.c src_pipex/ft_libft_functions.c src_pipex/ft_split.c src_pipex/ft_substr.c src_pipex/ft_strjoin.c src_pipex/ft_free.c)
