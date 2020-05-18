# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gstarvin <gstarvin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/20 17:25:08 by gstarvin          #+#    #+#              #
#    Updated: 2020/05/17 15:08:29 by sweet-cacao      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= lem-in
INC_DIR	= ./includes
SRC_DIR = ./src/

FL = -Wall -Wextra -Werror

SRC			= belman_ford2.c first_answer2.c \
				first_answer.c graph_functions.c  print_ants.c \
				belman_ford.c first_answer3.c give_paths.c \
				main.c return_find.c \
				del_lists.c first_answer4.c  graph_functions2.c \
				parse_and_solve.c solution_graph_sorted.c \
				find_all_paths.c  first_answer5.c
				graph_functions3.c  parse.c print_graph.c

OBJ_DIR = ./objects/

LEM_IN_FILES = $(patsubst %.c, %.o, $(SRC))
LEM_IN_OBJECTS = $(addprefix $(OBJ_DIR), $(PUSH_SWAP_FILES))

HEADERS_DIRECTORY = ./includes/
HEADER_FILES = lem-in.h
HEADERS = $(addprefix $(HEADERS_DIRECTORY), $(HEADER_FILES))

LIBFT	= ./libft

IFL		= -I$(INC_DIR)

WFL 	= -Wall -Wextra -Werror

SRCS	= $(addprefix $(SRC))

all: $(NAME)

$(NAME): $(LEM_IN_OBJECTS)
	$(MAKE) -C $(LIBFT)/
	gcc $(FL) $^ $(LIBFT)/libftprintf.a $(IFL) -o $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HEADERS)
	mkdir -p ./objects
	gcc $(FL) -c $< -o $@ -I $(HEADERS_DIRECTORY)

clean:
	$(MAKE) -C $(LIBFT) clean
	/bin/rm -rf $(OBJ_DIR)

fclean: clean
	$(MAKE) -C $(LIBFT) fclean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
