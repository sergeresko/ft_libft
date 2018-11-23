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

/*
	long long	num;

	num = strtoll(argv[2], NULL, 10);
	i = ft_printf(format, num);
	ft_putstr("\e[31m(length = ");
	ft_putnbr(i);
	ft_putstr(")\e[0m\n");
	i = printf(format, num);
	fflush(NULL);
	ft_putstr("\e[31m(length = ");
	ft_putnbr(i);
	ft_putstr(")\e[0m\n");
*/

	const char	*s;

	s = argv[2];
	i = ft_printf(format, s);
	printf("\e[31m(length = %d)\e[0m\n", i);
	i = printf(format, s);
	printf("\e[31m(length = %d)\e[0m\n", i);

	return (0);
}
