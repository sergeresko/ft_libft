/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xcheck.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 19:50:21 by syeresko          #+#    #+#             */
/*   Updated: 2018/11/25 15:36:07 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

typedef int		(*t_func)(const char *, ...);
typedef void	(*t_test)(t_func);
typedef struct	s_pair
{
	char		*name;
	t_test		address;
}				t_pair;

int				ft_printf(const char *, ...);

int				res;

#define TEST(name) void name(t_func f)

#define T(name) {#name, name}

#define PF(...)							\
	f("\e[31m(%s)\e[0m", #__VA_ARGS__);	\
	res = f(__VA_ARGS__);				\
	f("\e[31m(%d)\e[0m\n", res);

#define ARRAY_LEN(array) sizeof(array) / sizeof(*array)

#define FOREACH(x,array) for (int x = 0; x < ARRAY_LEN(array); ++x)

#define ALL_TESTS(...) t_pair g_tests[] = {{NULL, NULL}, __VA_ARGS__};

#include "xtests.h"

void			stop(void)
{
	fprintf(stderr, "Available tests:\n");
	for (int i = 1; i < ARRAY_LEN(g_tests); ++i)
		fprintf(stderr, "[%d]%s ", i, g_tests[i].name);
	fprintf(stderr, "\n");
	exit(1);
}

int				main(int argc, char **argv)
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
