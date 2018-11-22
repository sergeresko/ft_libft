#include <stdlib.h>

/*
**	Returns 0 if 'n' is 0.
**	Maximum length is 10 digits, hence the condition in 'while'.
*/

static int	length(unsigned n)
{
	int			i;
	unsigned	round;

	if (n == 0)
		return (0);
	i = 0;
	round = 1;
	while (round <= n && i < 10)
	{
		++i;
		round *= 10;
	}
	return (i);
}

int			dec_unsigned(char **as, unsigned n)
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
		*(--i) = '0' + n % 10;
		n /= 10;
	}
	return (len);
}
