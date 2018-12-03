# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: syeresko <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/14 19:06:47 by syeresko          #+#    #+#              #
#    Updated: 2018/12/03 13:11:03 by syeresko         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = \
		ft_printf.c				\
		parse_format.c			\
		pf_itoa.c				\
		pf_wctomb.c				\
		count_zeroes.c			\
		print_character.c		\
		print_wide_character.c	\
		print_integer.c			\
		print_string.c			\
		print_wide_string.c		\
		print_unsigned.c		\
		print_hexadecimal.c		\
		print_octal.c			\
		print_binary.c			\
		print_pointer.c			\
		print_long_double.c

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror -c ./libft/*.c -I./libft
	gcc -Wall -Wextra -Werror -c $(SRC) -I./libft
	ar rc $(NAME) *.o
	ranlib $(NAME)

clean:
	rm -rf *.o

fclean: clean
	rm -rf $(NAME)

re: fclean all
