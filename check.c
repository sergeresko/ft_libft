#include "ft_printf.h"
#include <stdio.h>
#include <stdlib.h>

typedef int		(*t_func)(const char *, ...);
typedef void	(*t_test)(t_func);

void	test00(t_func f)
{
	int		n;

	n = f("%d", 42);
	f("\e[31m(%d)\e[0m\n", n);
}

void	test01(t_func f)
{
	int		n;

	n = f("%o", 0);
	f("\e[31m(%d)\e[0m\n", n);
	n = f("%.o", 0);
	f("\e[31m(%d)\e[0m\n", n);
	n = f("%.0o", 0);
	f("\e[31m(%d)\e[0m\n", n);
	n = f("%.1o", 0);
	f("\e[31m(%d)\e[0m\n", n);
	n = f("%.2o", 0);
	f("\e[31m(%d)\e[0m\n", n);
	n = f("%.3o", 0);
	f("\e[31m(%d)\e[0m\n", n);

	n = f("%o", 0);
	f("\e[31m(%d)\e[0m\n", n);
	n = f("%.o", 3);
	f("\e[31m(%d)\e[0m\n", n);
	n = f("%.0o", 3);
	f("\e[31m(%d)\e[0m\n", n);
	n = f("%.1o", 3);
	f("\e[31m(%d)\e[0m\n", n);
	n = f("%.2o", 3);
	f("\e[31m(%d)\e[0m\n", n);
	n = f("%.3o", 3);
	f("\e[31m(%d)\e[0m\n", n);

	n = f("%o", 42);
	f("\e[31m(%d)\e[0m\n", n);
	n = f("%.o", 42);
	f("\e[31m(%d)\e[0m\n", n);
	n = f("%.0o", 42);
	f("\e[31m(%d)\e[0m\n", n);
	n = f("%.1o", 42);
	f("\e[31m(%d)\e[0m\n", n);
	n = f("%.2o", 42);
	f("\e[31m(%d)\e[0m\n", n);
	n = f("%.3o", 42);
	f("\e[31m(%d)\e[0m\n", n);
}

void	test02(t_func f)
{
	int		n;

	n = f("%#o", 0);
	f("\e[31m(%d)\e[0m\n", n);
	n = f("%#.o", 0);
	f("\e[31m(%d)\e[0m\n", n);
	n = f("%#.0o", 0);
	f("\e[31m(%d)\e[0m\n", n);
	n = f("%#.1o", 0);
	f("\e[31m(%d)\e[0m\n", n);
	n = f("%#.2o", 0);
	f("\e[31m(%d)\e[0m\n", n);
	n = f("%#.3o", 0);
	f("\e[31m(%d)\e[0m\n", n);

	n = f("%#o", 0);
	f("\e[31m(%d)\e[0m\n", n);
	n = f("%#.o", 3);
	f("\e[31m(%d)\e[0m\n", n);
	n = f("%#.0o", 3);
	f("\e[31m(%d)\e[0m\n", n);
	n = f("%#.1o", 3);
	f("\e[31m(%d)\e[0m\n", n);
	n = f("%#.2o", 3);
	f("\e[31m(%d)\e[0m\n", n);
	n = f("%#.3o", 3);
	f("\e[31m(%d)\e[0m\n", n);

	n = f("%#o", 42);
	f("\e[31m(%d)\e[0m\n", n);
	n = f("%#.o", 42);
	f("\e[31m(%d)\e[0m\n", n);
	n = f("%#.0o", 42);
	f("\e[31m(%d)\e[0m\n", n);
	n = f("%#.1o", 42);
	f("\e[31m(%d)\e[0m\n", n);
	n = f("%#.2o", 42);
	f("\e[31m(%d)\e[0m\n", n);
	n = f("%#.3o", 42);
	f("\e[31m(%d)\e[0m\n", n);
}

void	test03(t_func f)
{
	int		n;

	n = f("%d", 3);
	f("\e[31m(%d)\e[0m\n", n);
}

t_test	g_tests[] =
{
	test00,
	test01,
	test02,
	test03,
};

void	stop(void)
{
	printf("Error\n");
	exit(1);
}

int		main(int argc, char **argv)
{
	t_func	f;
	int		i;
	int		j;
	
	if (argc != 3)
		stop();
	i = atoi(argv[1]);
	if (i == 1)
		f = ft_printf;
	else if (i == 2)
		f = printf;
	else
		stop();
	j = atoi(argv[2]);
	if (0 <= j && j < sizeof(g_tests) / sizeof(t_func))
		g_tests[j](f);
	else
		stop();
	return (0);
}
