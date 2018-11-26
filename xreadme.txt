# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    xreadme.txt                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: syeresko <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/25 13:26:53 by syeresko          #+#    #+#              #
#    Updated: 2018/11/26 16:31:28 by syeresko         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


PREPARATION

Copy the files from this directory to the root of your ft_printf repository.
The names of all these files start with letter 'x' for convenience, so that
they hopefully don't mix with your own files.
Alternatively, if you want to keep them in a seperate directory, open the file
"xmake" with a text editor and specify the path to your "libftprintf.a" there.

To let the shell scripts be executed without prepending "sh" each time, run
	"chmod +x xmake"
	"chmod +x x"



GENERAL USAGE

/-------------------------------\
|	...							|
|		(all your source files)	|
|	Makefile					|
|		(your Makefile)			|
\-------------------------------/
				|
				|		"make" OR "make re"
				|			(run this if you need to rebuild your library,
				|			for example, if you have modified your source files)
				V
/-------------------------------\
|	libftprintf.a				|
|		(your library)			|
|	xcheck.c					|
|		(don't touch this)		|
|	xtests.h					|	<----	TESTS ARE HERE
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

If you don't want to compare your ft_printf with printf, but only want to see
the output produced by either of these functions, you may run
	"./xcheck 1 PARAMETER" (for ft_printf)
	OR
	"./xcheck 2 PARAMETER" (for printf)
where PARAMETER is the same as for "./x" described above.
Alternatively, you may run
	"./x PARAMETER"
and then
	"cat xout_ft.txt"
	OR
	"cat xout_libc.txt" 



TEST NAMING CONVENTION

The name of a test is composed of the following parts in succession:
1.	a capital letter B, H, U, X, or M
		B means a BASIC test: ft_printf must work exactly as printf.
		H means a HARD test: even if output is different, one can forgive this.
		U means a test where printf has UNDEFINED BEHAVIOR.
		X means an EXTRA test for bonus features not required in the subject.
		M means a MIXED test comprising miscellaneous test cases.
2.	1)	either one of the letters d, i, o, u, x, X, s, c, p, f, ...
		(if the test is designed for a speific conversion)
	2)	or an underscore (_)
		(if the test doesn't have a conversion or has different conversions)
3.	an arbitrary sequence of alphanumeric characters

Good test names are, for example:
	B_percent	(a basic test for "%%" conversion)
	Hf_1e150	(a hard test for "%f" that tests the number 10^150)
	U_two_stars	(a test for "%**", which is undefined by the standard)
	Xs_wide		(an extra test for "%ls")
	M_syeresko	(a test with various stuff by <syeresko>)

Bad test names are, for example:
	test001
	qweqweqwe



TEST SYNTAX

All tests reside in a text file named "xtests.h" and are written in the form
of macros. You are encouraged to add your own tests to that file.

There are five macros: PF, TEST, TEST_ITER, ALL_TESTS, and T.

If you examine "xtests.h" and look at the output files, you'll easily figure
out what these macros do and how to use them.

Test names are indicated as the argument of TEST macro or as the first argument
of TEST_ITER macro. For example, the following two tests do completely the same
thing:

1.	TEST(name)
	{
		PF("It %s an example", "is")
		PF("It %s an example", "could be")
		PF("It %s an example", "won't count as")
		PF("It %.2s an example", "is")
		PF("It %.2s an example", "could be")
		PF("It %.2s an example", "won't count as")
	}

2.	#define _name(x)\
		PF("It %s and example", x)\
		PF("It %.2s an example", x)
	TEST_ITER(name, "is", "could be", "won't count as")

NOTE 1:	There is NO SEMICOLON (;) after a PF call.
NOTE 2:	There is NO BACKSLASH (\) in the last line of #define.
NOTE 3:	The name in #define must be the same as the first argument of the
		following TEST_ITER, but with an underscore at the beginning.
NOTE 4:	If you add your tests, don't forget to list their names in ALL_TESTS
		at the end of file.



GOOD LUCK!
