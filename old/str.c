#include <stdlib.h>

static int	length(const char *str)
{
	int		i;

	while (*(str++))
		++i;
	return (i);
}

int			str(char **as, const char *str)
{
	int		len;
	char	*i;

	len = length(str);
	*as = (char *)malloc(len + 1);
	i = *as;
	while ((*(i++) = *(str++)))
		;
	return (len);
}
