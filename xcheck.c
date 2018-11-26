/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xcheck.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 19:50:21 by syeresko          #+#    #+#             */
/*   Updated: 2018/11/26 14:12:26 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

/*
**	MAP macro (C) 2012 William Swanson
**	https://github.com/swansontec/map-macro
*/

#define EVAL0(...)	__VA_ARGS__
#define EVAL1(...)	EVAL0(EVAL0(EVAL0(__VA_ARGS__)))
#define EVAL2(...)	EVAL1(EVAL1(EVAL1(__VA_ARGS__)))
#define EVAL3(...)	EVAL2(EVAL2(EVAL2(__VA_ARGS__)))
#define EVAL4(...)	EVAL3(EVAL3(EVAL3(__VA_ARGS__)))
#define EVAL(...)	EVAL4(EVAL4(EVAL4(__VA_ARGS__)))
#define MAP_END(...)
#define MAP_OUT
#define MAP_GET_END2()		0, MAP_END
#define MAP_GET_END1(...)	MAP_GET_END2
#define MAP_GET_END(...)	MAP_GET_END1
#define MAP_NEXT0(test, next, ...)	next MAP_OUT
#define MAP_NEXT1(test, next)	MAP_NEXT0(test, next, 0)
#define MAP_NEXT(test, next) 	MAP_NEXT1(MAP_GET_END test, next)
#define MAP0(f, x, peek, ...)	f(x) MAP_NEXT(peek, MAP1)(f, peek, __VA_ARGS__)
#define MAP1(f, x, peek, ...)	f(x) MAP_NEXT(peek, MAP0)(f, peek, __VA_ARGS__)
#define MAP(f, ...)		EVAL(MAP1(f, __VA_ARGS__, ()()(), ()()(), ()()(), 0))

/*
**	Definitions for checking ft_printf
*/

typedef int		(*t_func)(const char *, ...);
typedef void	(*t_test)(t_func);
typedef struct	s_pair
{
	char		*name;
	t_test		address;
}				t_pair;
int				ft_printf(const char *, ...);
int				res;

#define PF(...)\
	f("\e[31m(%s)\e[0m", #__VA_ARGS__);\
	res = f(__VA_ARGS__);\
	f("\e[31m(%d)\e[0m\n", res);
#define TEST(name)			void name(t_func f)
#define TEST_ITER(name,...) TEST(name){MAP(_##name,__VA_ARGS__)}
#define T(name)				{#name, name},
#define ALL_TESTS(...)		t_pair g_tests[] = {{NULL, NULL}, __VA_ARGS__};
#define TESTS_NUM			(sizeof(g_tests) / sizeof(*g_tests))
#define TEST_NAME(index)	(g_tests[index].name)
#define TEST_FUNC(index)	(g_tests[index].address)

#include "xtests.h"

int				prefix(const char *pre, const char *str)
{
	return (strncmp(pre, str, strlen(pre)) == 0);
}

void			stop(void)
{
	fprintf(stderr, "\e[32mAvailable tests:\e[0m\n");
	for (int i = 1; i < TESTS_NUM; ++i)
		fprintf(stderr, "\e[32m[%d]\e[0m%s ", i, g_tests[i].name);
	fprintf(stderr, "\n");
	exit(1);
}

int				main(int argc, char **argv)
{
	t_func		f;
	int			i;
	
	if (argc != 3)
		stop();
	i = atoi(argv[1]);
	if (i == 1)
		f = ft_printf;
	else if (i == 2)
		f = printf;
	else
		stop();
	if (argv[2][0] == '-')
	{
		for (i = 1; i < TESTS_NUM; ++i)
			if (prefix(argv[2] + 1, TEST_NAME(i)))
				TEST_FUNC(i)(f);
		return (0);
	}
	i = atoi(argv[2]);
	if (i == 0)
	{
		for (i = 1; i < TESTS_NUM; ++i)
			if (strcmp(argv[2], TEST_NAME(i)) == 0)
				break ;
	}
	if (0 < i && i < TESTS_NUM)
		TEST_FUNC(i)(f);
	else
		stop();
	return (0);
}
