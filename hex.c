#include <stdlib.h>

/*
**	Returns 0 if 'n' is 0.
*/

static int	length(unsigned n)
{
	int		i;

	i = 0;
	while (n)
	{
		++i;
		n >>= 4;
	}
	return (i);
}

/*
**	To make this function use uppercase letters, replace 'a' with 'A'
**	in the fifth line from last.
*/

int			hex(char **as, unsigned n)
{
	int			len;
	char		*i;
	unsigned	digit;

	len = length(n);
	*as = (char *)malloc(len + 1);
	i = *as + len;
	*i = '\0';
	if (n == 0)
		*(--i) = '0';
	while (n)
	{
		digit = n & 15;
		*(--i) = (digit < 10) ? ('0' + digit) : ('a' + digit - 10);
		n >>= 4;
	}
	return (len);
}
