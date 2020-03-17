
NAME		= libftprintf.a

INC_DIR		= ./includes 
SRC_DIR		= ./ft_printf

HEADERS		= ft_printf.h
SRC     	= \
			  check_format.c \
			  common_functions.c \
			  \
			  count_length.c \
			  format_percent.c \
			  format_print_c.c \
			  format_print_di.c \
			  format_print_di_extra.c \
			  \
			  format_print_p.c \
			  format_print_p_extra.c	\
			  format_print_str.c \
			  format_print_u.c \
			  format_print_u_one.c \
			  format_print_u_three.c \
			  format_print_u_two.c \
			  format_print_u_four.c \
			  ft_float.c \
			  ft_float_one.c \
			  ft_float_two.c \
			  ft_parse.c \
			  ft_putchar_fd_my.c \
			  \
			  ft_printf.c \
			  ft_putnbr_my.c \
			  hex_oct.c \
			  print_oxp.c \
			  star_functions.c \
			  time.c \
			  binary.c \
			  ft_printf_add.c \
			  \

OBJS = $(SRC:.c=.o)

LIBFT = ./ft_str

WFL = -Wall -Wextra -Werror

IFL = -I$(INC_DIR)

SRCS = $(addprefix $(SRC_DIR))

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFT)/
	cp $(LIBFT)/libft.a ./$(NAME)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

%.o: $(SRC_DIR)/%.c
	gcc $(WFL) $(IFL) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFT)/ clean
	rm -rf $(OBJS)

fclean: clean
	$(MAKE) -C $(LIBFT)/ fclean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
