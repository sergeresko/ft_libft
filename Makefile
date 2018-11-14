# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: syeresko <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/14 19:06:47 by syeresko          #+#    #+#              #
#    Updated: 2018/11/14 19:09:01 by syeresko         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror ft_printf.c -c
	ar rc $(NAME) ft_printf.o

clean:
	rm ft_printf.o

fclean: clean
	rm $(NAME)

re: fclean all
