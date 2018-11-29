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
	PF("%-#14.4u", n)\
	PF("%0u", n)
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
	PF("%-#14.4x", n)\
	PF("%0x", n)
TEST_ITER(Bx_book, 42, -42)

#define _BX_book(n)\
	PF("%X", n)\
	PF("%14X", n)\
	PF("%014X", n)\
	PF("%#14X", n)\
	PF("%#014X", n)\
	PF("%-14X", n)\
	PF("%-#14X", n)\
	PF("%14.4X", n)\
	PF("%-14.4X", n)\
	PF("%-#14.4X", n)\
	PF("%0X", n)
TEST_ITER(BX_book, 42, -42)

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
	PF("%-12s", s)\
	PF("%12.10s", s)
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
	PF("%.3o", n)\
	PF("%03o", n)
TEST_ITER(Bo_nosharp, 0, 3, 19, 73, 100)

/* octal with '#' */
#define _Bo_sharp(n)\
	PF("%#o", n)\
	PF("%#.o", n)\
	PF("%#.0o", n)\
	PF("%#.1o", n)\
	PF("%#.2o", n)\
	PF("%#.3o", n)\
	PF("%0o", n)\
	PF("%#03o", n)
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
	PF("%0.27p", p)\
	PF("%-010p", p)\
	PF("%-010.7p", p)\
	PF("%.p", p)
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
	PF("%0d", 0)
END

TEST(Hdi_zero)
	PF("%0d", 0)
	PF("%010d", 0)
	PF("%0d", 10)
	PF("%010d", 10)
	PF("%0.d", 0)
	PF("%0.d", 10)
	PF("%0d", 0)
	PF("%010.12d", 10)
	PF("%010.12d", 0)
	PF("%010.d", 0)
	PF("%010.d", 10)
END

TEST(Hu_zero)
	PF("%0u", 0)
	PF("%010u", 0)
	PF("%0u", 10)
	PF("%010u", 10)
	PF("%0.u", 0)
	PF("%0.u", 10)
	PF("%0u", 0)
	PF("%010.12u", 10)
	PF("%010.12u", 0)
	PF("%010.u", 0)
	PF("%010.u", 10)
END


TEST(HxX_zero)
	PF("%0x", 0)
	PF("%010X", 0)
	PF("%0X", 10)
	PF("%010x", 10)
	PF("%0.X", 0)
	PF("%0.x", 10)
	PF("%0X", 0)
	PF("%010.12X", 10)
	PF("%010.12x", 0)
	PF("%010.X", 0)
	PF("%010.X", 10)
END

TEST(Hp_zero)
	PF("%0p", 0)
	PF("%010p", 0)
	PF("%0p", 10)
	PF("%010p", 10)
	PF("%0.p", 0)
	PF("%0.p", 10)
	PF("%0p", 0)
	PF("%010.12p", 10)
	PF("%010.12p", 0)
	PF("%010.p", 0)
	PF("%010.p", 10)
END

TEST(Ho_zero)
	PF("%0o", 0)
	PF("%010o", 0)
	PF("%0o", 10)
	PF("%010o", 10)
	PF("%0.o", 0)
	PF("%0.o", 10)
	PF("%0o", 0)
	PF("%010.12o", 10)
	PF("%010.12o", 0)
	PF("%010.o", 0)
	PF("%010.o", 10)
END

TEST(H_percent_zero)
	PF("%0%", 0)
	PF("%010%", 0)
	PF("%0%", 10)
	PF("%010%", 10)
	PF("%0.%", 0)
	PF("%0.%", 10)
	PF("%0%", 0)
	PF("%010.12%", 10)
	PF("%010.12%", 0)
	PF("%010.%", 0)
	PF("%010.%", 10)
END

TEST(Hs_zero)
	PF("%0s", "a")
	PF("%010s", "a")
	PF("%0s", "a")
	PF("%010s", "a")
	PF("%0.s", "a")
	PF("%0.s", "a")
	PF("%0s", "a")
	PF("%010.12s", "a")
	PF("%010.12s", "a")
	PF("%010.s", "a")
	PF("%010.s", "10")
END


TEST(Bd_lh)
	PF("%ld", 4294967295)
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
	T(Bd_lh)
	T(BX_book)
	T(Hs_zero) T(H_percent_zero) T(Ho_zero) T(Hp_zero)
	T(Hu_zero) T(HxX_zero) T(Hdi_zero)

/*
**	Add the names of your test here.
*/

)
