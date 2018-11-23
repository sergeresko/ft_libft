#include <stdlib.h>
#include <stdio.h>
#include "ft_printf.h"

int		main(int argc, char **argv)
{
	int			i;
	char		*format;

	if (argc != 3)
		return (0);
	format = argv[1];

	long long	num;

	num = strtoll(argv[2], NULL, 10);
	i = ft_printf(format, num);
	printf("\e[31m(length = %d)\e[0m\n", i);
	i = printf(format, num);
	printf("\e[31m(length = %d)\e[0m\n", i);

/*
	const char	*s;

//	s = argv[2];
	s = NULL;
	i = ft_printf(format, s);
	printf("\e[31m(length = %d)\e[0m\n", i);
	i = printf(format, s);
	printf("\e[31m(length = %d)\e[0m\n", i);
*/
	return (0);
}
