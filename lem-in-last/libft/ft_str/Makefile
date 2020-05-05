# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mburnett <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/16 18:19:52 by mburnett          #+#    #+#              #
#    Updated: 2020/02/18 10:53:41 by gstarvin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Wextra -Werror
SD = ../ft_sort/
SRCS = ft_isalpha.c ft_isalnum.c ft_strcat.c ft_strcmp.c ft_strcpy.c ft_strdup.c ft_strlen.c ft_bzero.c \
       ft_strncat.c ft_strncmp.c ft_strncpy.c ft_isascii.c ft_isprint.c ft_isdigit.c ft_toupper.c ft_tolower.c \
       ft_strstr.c ft_strnstr.c ft_atoi.c ft_memcpy.c ft_memccpy.c ft_memcmp.c ft_memmove.c ft_memset.c ft_memchr.c \
       ft_strlcat.c ft_strchr.c ft_strrchr.c \
       ft_putchar.c ft_putchar_fd.c ft_putstr.c ft_putnbr.c ft_putstr_fd.c ft_putendl.c ft_putendl_fd.c ft_putnbr_fd.c \
       ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c ft_strclr.c \
       ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c \
       ft_strjoin.c ft_strsub.c ft_itoa.c \
       ft_strtrim.c ft_strsplit.c ft_strlcat.c \
       ft_countletters.c ft_countwds.c \
       ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c \
	   get_next_line.c massiv_del.c \
	   $(SD)get_next.c \
	   $(SD)add_block.c \
	   $(SD)push_end.c \
	   $(SD)push_front.c \
	   $(SD)delete_first.c \
	   $(SD)delete_last.c \
	   $(SD)sort_del.c

OBJ = $(SRCS:.c=.o)
INCL = libft.h
NAME = libft.a

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

%.o: %.c
	gcc $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
