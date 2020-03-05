cmake_minimum_required(VERSION 3.15)
project(lem_in C)

set(CMAKE_C_STANDARD 99)

add_executable(lem_in src/main.c src/graph_functions.c includes/lem-in.h src/solution_functions.c src/BFS.c
        libft/ft_str/ft_strcmp.c src/find_answers.c src/delete_useful_links.c src/suurbale.c src/belman-ford.c
        src/print_graph.c src/L-print.c src/parse.c
        libft/ft_str/ft_strsplit.c
        libft/ft_str/ft_putstr.c
        libft/ft_str/ft_putchar.c
        libft/ft_str/ft_strstr.c
        libft/ft_str/get_next_line.c
        libft/ft_str/ft_strchr.c
        libft/ft_str/ft_strlen.c
        libft/ft_str/ft_atoi.c
        libft/ft_str/ft_countletters.c
        libft/ft_str/ft_countwds.c
        libft/ft_str/ft_strdel.c
        libft/ft_str/ft_strdup.c
        libft/ft_str/ft_strjoin.c
        libft/ft_str/ft_strnew.c
        libft/ft_str/ft_strsub.c
        libft/ft_str/ft_bzero.c
        libft/ft_str/ft_memdel.c)

#find_library(LIBFT_LIB print libft)
#target_link_libraries(lem_in LINK_PUBLIC ${LIBFT_LIB})
