cmake_minimum_required(VERSION 3.15)
project(lem_in C)

set(CMAKE_C_STANDARD 99)

add_executable(lem_in src/main.c src/graph_functions.c includes/lem-in.h src/solution_functions.c src/BFS.c
        libft/ft_str/ft_strcmp.c src/find_answers.c src/delete_useful_links.c src/suurbale.c)

#find_library(LIBFT_LIB print libft)
#target_link_libraries(lem_in LINK_PUBLIC ${LIBFT_LIB})
