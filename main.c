#include <stdio.h>
#include "libft.h"
#include "ft_printf.h"

int		main(int argc, char **argv)
{
	int		i;
	char	*format;
	int		num;

	if (argc != 3)
		return (0);
	format = argv[1];
	num = ft_atoi(argv[2]);
	i = ft_printf(format, num);
	ft_putstr("\e[31m(length = ");
	ft_putnbr(i);
	ft_putstr(")\e[0m\n");
	i = printf(format, num);
	fflush(NULL);
	ft_putstr("\e[31m(length = ");
	ft_putnbr(i);
	ft_putstr(")\e[0m\n");
	return (0);
}
