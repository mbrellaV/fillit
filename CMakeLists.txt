cmake_minimum_required(VERSION 3.14)
project(fillit C)

set(CMAKE_C_STANDARD 11)

add_executable(fillit
        main.c ft_read_tetro.c ft_fillit.h ft_solver.c ft_dop_func.c)

target_link_libraries(fillit ${CMAKE_SOURCE_DIR}/libft/libft.a)