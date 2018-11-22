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
		n >>= 3;
	}
	return (i);
}

int			oct(char **as, unsigned n)
{
	int			len;
	char		*i;

	len = length(n);
	*as = (char *)malloc(len + 1);
	i = *as + len;
	*i = '\0';
	if (n == 0)
		*(--i) = '0';
	while (n)
	{
		*(--i) = '0' + (n & 7);
		n >>= 3;
	}
	return (len);
}
