/*
**	The book:
**	https://savedparadigms.files.wordpress.com/2014/09/harbison-s-p-steele-g-l-c-a-reference-manual-5th-ed.pdf
*/

/* examples from the book (p. 394) */
#define _Bd_book(n)\
	PF("%d", n)\
	PF("%12d", n)\
	PF("%012d", n)\
	PF("% 012d", n)\
	PF("%+12d", n)\
	PF("%+012d", n)\
	PF("%-12d", n)\
	PF("%- 12d", n)\
	PF("%-+12d", n)\
	PF("%12.4d", n)\
	PF("%-12.4d", n)
TEST_ITER(Bd_book, 42, -42)

/* examples from the book (p. 394) */
#define _Bu_book(n)\
	PF("%u", n)\
	PF("%14u", n)\
	PF("%014u", n)\
	PF("%#14u", n)\
	PF("%#014u", n)\
	PF("%-14u", n)\
	PF("%-#14u", n)\
	PF("%14.4u", n)\
	PF("%-14.4u", n)\
	PF("%-#14.4u", n)
TEST_ITER(Bu_book, 42, -42)

/* examples from the book (p. 395) */
#define _Bo_book(n)\
	PF("%o", n)\
	PF("%14o", n)\
	PF("%014o", n)\
	PF("%#14o", n)\
	PF("%#014o", n)\
	PF("%-14o", n)\
	PF("%-#14o", n)\
	PF("%14.4o", n)\
	PF("%-14.4o", n)\
	PF("%-#14.4o", n)
TEST_ITER(Bo_book, 42, -42)

/* examples from the book (p. 395) */
#define _Bx_book(n)\
	PF("%x", n)\
	PF("%14x", n)\
	PF("%014x", n)\
	PF("%#14x", n)\
	PF("%#014x", n)\
	PF("%-14x", n)\
	PF("%-#14x", n)\
	PF("%14.4x", n)\
	PF("%-14.4x", n)\
	PF("%-#14.4x", n)
TEST_ITER(Bx_book, 42, -42)

/* examples from the book (p. 396) */
TEST(Bc_book)
	PF("%c", '@')
	PF("%12c", '@')
	PF("%012c", '@')
	PF("%-12c", '@')
END

/* examples from the book (p. 397) */
#define _Bs_book(s)\
	PF("%s", s)\
	PF("%12s", s)\
	PF("%12.5s", s)\
	PF("%012s", s)\
	PF("%-12s", s)
TEST_ITER(Bs_book, "zap", "longish", NULL)

/* examples from the book (p. 398) */
#define _Bf_book(x)\
	PF("%f", x)\
	PF("%10.2f", x)\
	PF("%010.2f", x)\
	PF("% 010.2f", x)\
	PF("%+10.2f", x)\
	PF("%+010.2f", x)\
	PF("%-10.2f", x)\
	PF("%- 10.2f", x)\
	PF("%-+10.4f", x)
TEST_ITER(Bf_book, 12.678, -12.678)

/* octal without '#' */
#define _Bo_nosharp(n)\
	PF("%o", n)\
	PF("%.o", n)\
	PF("%.0o", n)\
	PF("%.1o", n)\
	PF("%.2o", n)\
	PF("%.3o", n)
TEST_ITER(Bo_nosharp, 0, 3, 19, 73, 100)

/* octal with '#' */
#define _Bo_sharp(n)\
	PF("%#o", n)\
	PF("%#.o", n)\
	PF("%#.0o", n)\
	PF("%#.1o", n)\
	PF("%#.2o", n)\
	PF("%#.3o", n)
TEST_ITER(Bo_sharp, 0, 3, 19, 73, 100)

/* precision passed through '*' */
TEST(X_prec_star)
	PF("%10.*d", -5, 42)
	PF("%10.*s", -5, "abc")
END

/* pointers */
#define _Bp(p)\
	PF("%p", p)\
	PF("%10p", p)\
	PF("%.7p", p)\
	PF("%-10p", p)\
	PF("%-10.7p", p)\
	PF("%0p", p)\
	PF("%010p", p)\
	PF("%0.7p", p)\
	PF("%-010p", p)\
	PF("%-010.7p", p)
TEST_ITER(Bp, NULL, ((void *)0x4242), ((void *)0x1a2b3c4d5e6f))

/* negative number */
TEST(Bd_negative)
	PF("%d", -12345678)
	PF("%7d", -12345678)
	PF("%8d", -12345678)
	PF("%9d", -12345678)
	PF("%10d", -12345678)
	PF("%20d", -12345678)

	PF("%-d", -12345678)
	PF("%-7d", -12345678)
	PF("%-8d", -12345678)
	PF("%-9d", -12345678)
	PF("%-10d", -12345678)
	PF("%-20d", -12345678)

	PF("%0d", -12345678)
	PF("%07d", -12345678)
	PF("%08d", -12345678)
	PF("%09d", -12345678)
	PF("%010d", -12345678)
	PF("%020d", -12345678)

	PF("%-0d", -12345678)
	PF("%0-7d", -12345678)
	PF("%-08d", -12345678)
	PF("%0-9d", -12345678)
	PF("%-010d", -12345678)
	PF("%0-20d", -12345678)

	PF("%.d", -12345678)
	PF("%7.d", -12345678)
	PF("%8.d", -12345678)
	PF("%9.d", -12345678)
	PF("%10.d", -12345678)
	PF("%20.d", -12345678)

	PF("%.0d", -12345678)
	PF("%7.0d", -12345678)
	PF("%8.0d", -12345678)
	PF("%9.0d", -12345678)
	PF("%10.0d", -12345678)
	PF("%20.0d", -12345678)

	PF("%.8d", -12345678)
	PF("%7.8d", -12345678)
	PF("%8.8d", -12345678)
	PF("%9.8d", -12345678)
	PF("%10.8d", -12345678)
	PF("%20.8d", -12345678)

	PF("%.9d", -12345678)
	PF("%7.9d", -12345678)
	PF("%8.9d", -12345678)
	PF("%9.9d", -12345678)
	PF("%10.9d", -12345678)
	PF("%20.9d", -12345678)

	PF("%.10d", -12345678)
	PF("%7.10d", -12345678)
	PF("%8.10d", -12345678)
	PF("%9.10d", -12345678)
	PF("%10.10d", -12345678)
	PF("%20.10d", -12345678)
END

/*
**	Add your tests here.
*/

ALL_TESTS(
	/* examples from the book */
	T(Bd_book) T(Bu_book) T(Bo_book) T(Bx_book) T(Bc_book) T(Bs_book) T(Bf_book)
	/* other tests */
	T(Bo_nosharp) T(Bo_sharp)
	T(X_prec_star)
	T(Bp)
	T(Bd_negative)

/*
**	Add the names of your test here.
*/

)
