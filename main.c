#include <unistd.h>
#include <stdlib.h>

int		ft_atoi(const char *s)
{
	int		sign;
	int		n;

	while (*s == ' ' || ('\t' <= *s && *s <= '\r'))
		++s;
	n = 0;
	sign = 1;
	if (*s == '-')
		sign = -1;
	if (*s == '+' || *s == '-')
		++s;
	while ('0' <= *s && *s <= '9')
	{
		n = n * 10 + sign * (int)(*s - '0');
		++s;
	}
	return (n);
}

int		dec_unsigned(char **as, unsigned n);
int		bin(char **as, unsigned n);
int		oct(char **as, unsigned n);
int		hex(char **as, unsigned n);

void	test(unsigned n, int (*f)())
{
	char	*s;
	int		len_1;
	int		len_2;

	len_1 = f(&s, n);
	if (s)
	{
		write(1, "\"", 1);
		write(1, s, len_1);
		free(s);
		write(1, "\" (", 3);
		len_2 = dec_unsigned(&s, len_1);
		write(1, s, len_2);
		free(s);
		write(1, " character", 10);
		if (len_1 != 1)
			write(1, "s", 1);
		write(1, ")\n", 2);
	}
}

int		main(int argc, char **argv)
{
	int			i;
	unsigned	number;

	if (argc == 1)
		write(1, "usage: ./test n1 [n2 [n3 [...]]]\n", 33);
	i = 1;
	while (i < argc)
	{
		number = ft_atoi(argv[i]);

		write(1, "dec: ", 5);
		test(number, dec_unsigned);

		write(1, "bin: ", 5);
		test(number, bin);

		write(1, "oct: ", 5);
		test(number, oct);

		write(1, "hex: ", 5);
		test(number, hex);

		write(1, "\n", 1);
		++i;
	}
	return (0);
}
