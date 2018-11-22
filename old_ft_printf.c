/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 17:21:58 by syeresko          #+#    #+#             */
/*   Updated: 2018/11/18 20:23:06 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>

int		dec(int n)
{
	char	c;

	c = '0' + n / 10;
	write(1, &c, 1);
	c = '0' + n % 10;
	write(1, &c, 1);
	return (2);
}

int		str(char *s)
{
	int		i;

	i = 0;
	while (s[i])
		++i;
	write(1, s, i);
	return (i);
}

int		my_print(int (*f)(), va_list ap)
{
	if (f == dec)
		return (f(va_arg(ap, int)));
	if (f == str)
		return (f(va_arg(ap, char *)));
	return (0);
}

/*
**	print_plain
**	writes string *a_str to the standard output until '\0' or '%' is encountered,
**	increments *a_str by the length of the written string
**	and returns this length.
*/

int		print_plain(const char **a_str)
{
	const char	*s;
	int			i;

	s = *a_str;
	i = 0;
	while (s[i] && s[i] != '%')
		++i;
	if (i)
		write(1, s, i);
	*a_str += i;
	return (i);
}

int		ft_printf(const char *format, ...)
{
	va_list		ap;
	int			len;

	len = 0;
	va_start(ap, format);
	while (1)
	{
		len += print_plain(&format);
		if (*format == '\0')
			break ;
		++format;
//
//		parse_format(&format, ap);
//
		
		if (*format == 'd')
		{
			len += my_print(dec, ap);
			++format;
		}
		else if (*format == 's')
		{
			len += my_print(str, ap);
			++format;
		}
		
	}
	va_end(ap);
	return (len);
}

int		main(void)
{
	int		i;

	i = ft_printf("AB%dCD%sEF%dGH%IJ\n", 12, "opqrst", 34);
	ft_printf("%d\n", i);
	return (0);
}
