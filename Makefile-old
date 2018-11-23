# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: syeresko <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/14 19:06:47 by syeresko          #+#    #+#              #
#    Updated: 2018/11/23 16:04:41 by syeresko         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror -c ./libft/*.c -I./libft
	gcc -Wall -Wextra -Werror -c [^m]*.c -I./libft
	ar rc $(NAME) *.o
	ranlib $(NAME)

clean:
	rm -rf *.o

fclean: clean
	rm -rf $(NAME)

re: fclean all
