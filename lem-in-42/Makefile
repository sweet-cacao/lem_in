# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gstarvin <gstarvin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/20 17:25:08 by gstarvin          #+#    #+#              #
#    Updated: 2020/05/18 21:53:34 by sweet-cacao      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= lem-in
SRC_DIR = ./src/

SRC			= belman_ford2.c \
			belman_ford.c \
			del_lists.c \
			find_all_paths.c \
			first_answer2.c \
			first_answer3.c \
			first_answer4.c \
			first_answer5.c \
			first_answer.c \
			give_paths.c \
			graph_functions2.c \
			graph_functions3.c \
			graph_functions.c \
			main.c \
			parse_and_solve.c \
			parse.c \
			print_ants.c \
			print_graph.c \
			return_find.c \
			solution_graph_sorted.c

OBJ_DIR = ./objects/

LEM_IN_FILES = $(patsubst %.c, %.o, $(SRC))
LEM_IN_OBJ = $(addprefix $(OBJ_DIR), $(LEM_IN_FILES))

HEADERS_DIRECTORY = ./includes/
HEADER_FILES = lemin.h
HEADERS = $(addprefix $(HEADERS_DIRECTORY), $(HEADER_FILES))

LIBFT	= ./libft

IFL		= -I$(HEADERS_DIRECTORY)

WFL 	=

SRCS	= $(addprefix $(SRC_DIR), $(SRC))

all: $(NAME)

$(NAME): $(LEM_IN_OBJ)
	$(MAKE) -C $(LIBFT)/
	gcc $(WFL) $^ $(LIBFT)/libftprintf.a $(IFL) -o $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HEADERS)
	mkdir -p ./objects
	gcc $(WFL) -c $< -o $@ -I $(HEADERS_DIRECTORY)

clean:
	$(MAKE) -C $(LIBFT) clean
	/bin/rm -rf $(OBJ_DIR)

fclean: clean
	$(MAKE) -C $(LIBFT) fclean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
