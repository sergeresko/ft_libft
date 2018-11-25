/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 19:50:21 by syeresko          #+#    #+#             */
/*   Updated: 2018/11/25 13:40:13 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int		res;

#define TEST(name) void name(t_func f)

#define T(name) {#name, name}

#define PF(...)							\
	f("\e[31m(%s)\e[0m", #__VA_ARGS__);	\
	res = f(__VA_ARGS__);				\
	f("\e[31m(%d)\e[0m\n", res);

#define ARRAY_LEN(array) sizeof(array) / sizeof(*array)

#define FOREACH(x,array) for (int x = 0; x < ARRAY_LEN(array); ++x)

typedef int		(*t_func)(const char *, ...);
typedef void	(*t_test)(t_func);
typedef struct	s_pair
{
	char	*name;
	t_test	address;
}				t_pair;

TEST(test00)
{
	PF("%d", 42)
}

TEST(test01)	/* octal without '#' */
{
	unsigned long long	values[] = {
		0,
		3,
		42,
	};

	FOREACH(i, values)
	{
		PF("%o", values[i])
		PF("%.o", values[i])
		PF("%.0o", values[i])
		PF("%.1o", values[i])
		PF("%.2o", values[i])
		PF("%.3o", values[i])
	}
}

TEST(test02)	/* octal with '#' */
{
	unsigned long long	values[] = {
		0,
		3,
		42,
	};

	FOREACH(i, values)
	{
		PF("%#o", values[i])
		PF("%#.o", values[i])
		PF("%#.0o", values[i])
		PF("%#.1o", values[i])
		PF("%#.2o", values[i])
		PF("%#.3o", values[i])
	}
}

TEST(test03)
{
	PF("%10.*d", -5, 42)

	PF("%10.*s", -5, "abc")
}

TEST(test04)	/* pointers */
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

TEST(test05)
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

t_pair	g_tests[] =
{
	{NULL, NULL},
	T(test00),
	T(test01),
	T(test02),
	T(test03),
	T(test04),
	T(test05),
};

void	stop(void)
{
	fprintf(stderr, "?\n");
	printf("Error\n");
	exit(1);
}

int		main(int argc, char **argv)
{
	t_func	f;
	int		i;
	
	if (argc != 3)
		stop();
	i = atoi(argv[1]);
	if (i == 1)
		f = ft_printf;
	else if (i == 2)
		f = printf;
	else
		stop();
	i = atoi(argv[2]);
	if (i == 0)
	{
		for (i = 1; i < ARRAY_LEN(g_tests); ++i)
		{
			if (strcmp(argv[2], g_tests[i].name) == 0)
				break ;
		}
	}
	if (1 <= i && i < ARRAY_LEN(g_tests))
		g_tests[i].address(f);
	else
		stop();
	return (0);
}
