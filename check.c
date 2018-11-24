/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 19:50:21 by syeresko          #+#    #+#             */
/*   Updated: 2018/11/24 21:12:47 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <stdlib.h>

#define PF(...)							\
	n = f(__VA_ARGS__);					\
	f("\e[31m(%d)\e[0m\n", n);

#define FOREACH(i,values)				\
	for (int i = 0; i < sizeof(values) / sizeof(values[0]); ++i)

typedef int		(*t_func)(const char *, ...);
typedef void	(*t_test)(t_func);

void	test00(t_func f)
{
	int		n;

	PF("%d", 42)
}

void	test01(t_func f)	/* octal without '#' */
{
	int		n;

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

void	test02(t_func f)	/* octal with '#' */
{
	int		n;
	
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

void	test03(t_func f)
{
	int		n;

	PF("%10.*d", -5, 42)

	PF("%10.*s", -5, "abc")
}

void	test04(t_func f)	/* pointers */
{
	int		n;

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

void	test05(t_func f)
{
	int		n;

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

t_test	g_tests[] =
{
	test00,
	test01,
	test02,
	test03,
	test04,
	test05,
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
	if (0 <= i && i < sizeof(g_tests) / sizeof(t_test))
		g_tests[i](f);
	else
		stop();
	return (0);
}
