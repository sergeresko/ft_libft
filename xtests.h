/*
**	The book:
**	https://savedparadigms.files.wordpress.com/2014/09/harbison-s-p-steele-g-l-c-a-reference-manual-5th-ed.pdf
*/

TEST(d42)		/* examples from the book (p. 394) */
{
	PF("%d", 42)
	PF("%12d", 42)
	PF("%012d", 42)
	PF("% 012d", 42)
	PF("%+12d", 42)
	PF("%+012d", 42)
	PF("%-12d", 42)
	PF("%- 12d", 42)
	PF("%-+12d", 42)
	PF("%12.4d", 42)
	PF("%-12.4d", 42)
}

TEST(dm42)		/* examples from the book (p. 394) */
{
	PF("%d", -42)
	PF("%12d", -42)
	PF("%012d", -42)
	PF("% 012d", -42)
	PF("%+12d", -42)
	PF("%+012d", -42)
	PF("%-12d", -42)
	PF("%- 12d", -42)
	PF("%-+12d", -42)
	PF("%12.4d", -42)
	PF("%-12.4d", -42)
}

TEST(u42)		/* examples from the book (p. 394) */
{
	PF("%u", 42)
	PF("%14u", 42)
	PF("%014u", 42)
	PF("%#14u", 42)
	PF("%#014u", 42)
	PF("%-14u", 42)
	PF("%-#14u", 42)
	PF("%14.4u", 42)
	PF("%-14.4u", 42)
	PF("%-#14.4u", 42)
}

TEST(um42)		/* examples from the book (p. 394) */
{
	PF("%u", -42)
	PF("%14u", -42)
	PF("%014u", -42)
	PF("%#14u", -42)
	PF("%#014u", -42)
	PF("%-14u", -42)
	PF("%-#14u", -42)
	PF("%14.4u", -42)
	PF("%-14.4u", -42)
	PF("%-#14.4u", -42)
}

TEST(o42)		/* examples from the book (p. 395) */
{
	PF("%o", 42)
	PF("%14o", 42)
	PF("%014o", 42)
	PF("%#14o", 42)
	PF("%#014o", 42)
	PF("%-14o", 42)
	PF("%-#14o", 42)
	PF("%14.4o", 42)
	PF("%-14.4o", 42)
	PF("%-#14.4o", 42)
}

TEST(om42)		/* examples from the book (p. 395) */
{
	PF("%o", -42)
	PF("%14o", -42)
	PF("%014o", -42)
	PF("%#14o", -42)
	PF("%#014o", -42)
	PF("%-14o", -42)
	PF("%-#14o", -42)
	PF("%14.4o", -42)
	PF("%-14.4o", -42)
	PF("%-#14.4o", -42)
}

TEST(x42)		/* examples from the book (p. 395) */
{
	PF("%x", 42)
	PF("%14x", 42)
	PF("%014x", 42)
	PF("%#14x", 42)
	PF("%#014x", 42)
	PF("%-14x", 42)
	PF("%-#14x", 42)
	PF("%14.4x", 42)
	PF("%-14.4x", 42)
	PF("%-#14.4x", 42)
}

TEST(xm42)		/* examples from the book (p. 395) */
{
	PF("%x", -42)
	PF("%14x", -42)
	PF("%014x", -42)
	PF("%#14x", -42)
	PF("%#014x", -42)
	PF("%-14x", -42)
	PF("%-#14x", -42)
	PF("%14.4x", -42)
	PF("%-14.4x", -42)
	PF("%-#14.4x", -42)
}

TEST(c1)		/* examples from the book (p. 396) */
{
	PF("%c", '@')
	PF("%12c", '@')
	PF("%012c", '@')
	PF("%-12c", '@')
}

TEST(s1)		/* examples from the book (p. 397) */
{
	PF("%s", "zap")
	PF("%12s", "zap")
	PF("%12.5s", "zap")
	PF("%012s", "zap")
	PF("%-12s", "zap")

	PF("%s", "longish")
	PF("%12s", "longish")
	PF("%12.5s", "longish")
	PF("%012s", "longish")
	PF("%-12s", "longish")

	PF("%s", NULL)
	PF("%12s", NULL)
	PF("%12.5s", NULL)
	PF("%012s", NULL)
	PF("%-12s", NULL)
}

TEST(o1)		/* octal without '#' */
{
	unsigned long long	val[] = {
		0,
		3,
		19,
		73,
		100,
	};

	FOREACH(i, val)
	{
		PF("%o", val[i])
		PF("%.o", val[i])
		PF("%.0o", val[i])
		PF("%.1o", val[i])
		PF("%.2o", val[i])
		PF("%.3o", val[i])
	}
}

TEST(o2)		/* octal with '#' */
{
	unsigned long long	val[] = {
		0,
		3,
		19,
		73,
		100,
	};

	FOREACH(i, val)
	{
		PF("%#o", val[i])
		PF("%#.o", val[i])
		PF("%#.0o", val[i])
		PF("%#.1o", val[i])
		PF("%#.2o", val[i])
		PF("%#.3o", val[i])
	}
}

TEST(test03)	/* precision passed through '*' */
{
	PF("%10.*d", -5, 42)

	PF("%10.*s", -5, "abc")
}

TEST(p1)		/* pointers */
{
	PF("%p", NULL)
	PF("%10p", NULL)
	PF("%.7p", NULL)
	PF("%-10p", NULL)
	PF("%-10.7p", NULL)
	PF("%0p", NULL)
	PF("%010p", NULL)
	PF("%0.7p", NULL)
	PF("%-010p", NULL)
	PF("%-010.7p", NULL)

	PF("%p", (void *)0x424242)

	PF("%p", (void *)0x1a2b3c4d5e6f)
}

TEST(dneg)		/* negative integer */
{
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
}

/*
**	Add your tests here.
*/

ALL_TESTS(
	T(d42),
	T(dm42),
	T(u42),
	T(um42),
	T(o42),
	T(om42),
	T(x42),
	T(xm42),
	T(c1),
	T(s1),
	T(o1),
	T(o2),
	T(test03),
	T(p1),
	T(dneg),

/*
**	Add the names of your test here.
*/

)
