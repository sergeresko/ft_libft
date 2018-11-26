# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    xreadme.txt                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: syeresko <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/25 13:26:53 by syeresko          #+#    #+#              #
#    Updated: 2018/11/26 14:20:12 by syeresko         ###   ########.fr        #
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
				|		"./x"
				|			(run this to see the list of all tests)
				|		"./x test_name" OR "./x test_number"
				|			(run this to see the diff for a particular test)
				|		"./x -prefix"
				|			(run this to see the diff for all tests whose names
				|			start with a particular prefix, e.g. "./x -Bu")
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



TEST NAMING CONVENTION

The name of a test is composed of the following parts in succession:
1.	a capital letter B, H, U, X
		B means a BASIC test: ft_printf must work exactly as printf.
		H means a HARD test: even if output is different, one can forgive this.
		U means a test where printf has UNDEFINED BEHAVIOR.
		X means an EXTRA test for bonus features not required in the subject.
		M means a MIXED test comprising miscellaneous test cases.
2.	1)	either one of the letters d, i, o, u, x, X, s, c, p, f, ...
		(if the test is designed for a speific convertion)
	2)	or an underscore (_)
		(if the test doesn't have a conversion or has different convertions)
3.	an arbitrary sequence of alphanumeric characters

Good test names are, for example:
	B_percent	(a basic test for "%%" conversion)
	Hf_e150		(a hard test for "%f" that tests the number 10^150)
	U_two_stars	(a test for "%**", which is undefined by the standard)
	Xs_wide		(an extra test for "%ls")
	M_syeresko	(a test with various stuff by <syeresko>)

Bad test names are, for example:
	test001
	qweqweqwe
