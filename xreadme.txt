# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    xreadme.txt                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: syeresko <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/25 13:26:53 by syeresko          #+#    #+#              #
#    Updated: 2018/11/25 15:02:31 by syeresko         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

It may be necessary to run
	"chmod +x xmake"
	"chmod +x x"
at first.

/-------------------------------\
|	...							|
|		(all your source files)	|
|	Makefile					|
|		(your Makefile)			|
\-------------------------------/
				|
				|		"make" OR "make re"
				|			(run this if you have modified your source files)
				V
/-------------------------------\
|	libftprintf.a				|
|		(your library)			|
|	xcheck.c					|
|		(don't touch this)		|
|	xtests.h					|	<----	tests are here
|		(tests you can expand)	|
\-------------------------------/
				|
				|		"./xmake"
				|			(run this if you have run the previous command
				|			or modified the file "xtests.h")
				V
/-------------------------------\
|	xcheck						|
|		(compiled tests)		|
\-------------------------------/
				|
				|		"./x test_name" OR "./x test_number"
				|			(run this to see the diff for a particular test)
				V
/-------------------------------\
|	xout_ft.txt					|
|		(ft_printf output)		|
|	xout_libc.txt				|
|		(printf output)			|
\-------------------------------/
				|
				|		"cat xout_ft.txt" OR "cat xout_libc.txt"
				|			(run this to see the whole output file)
				V
