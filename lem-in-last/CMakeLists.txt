cmake_minimum_required(VERSION 3.15)
project(lem_in C)

set(CMAKE_C_STANDARD 99)

add_executable(lem_in src/main.c src/graph_functions.c src/lemin.h src/solution_graph_sorted.c
        libft/ft_str/ft_strcmp.c src/return_find.c src/find_all_paths.c
        src/print_graph.c src/parse.c
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
        libft/ft_str/ft_memdel.c src/give_paths.c src/belman_ford.c src/print_ants.c src/parser/extra_functions.c src/del_lists.c src/parse_and_solve.c src/first_answer.c src/first_answer2.c src/first_answer3.c src/first_answer4.c src/first_answer5.c src/belman_ford2.c src/graph_functions2.c src/graph_functions3.c)

#find_library(LIBFT_LIB print libft)
#target_link_libraries(lem_in LINK_PUBLIC ${LIBFT_LIB})
