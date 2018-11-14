/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 17:21:58 by syeresko          #+#    #+#             */
/*   Updated: 2018/11/14 19:04:48 by syeresko         ###   ########.fr       */
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

int		print_plain(const char *str)
{
	int		i;

	i = 0;
	while (str[i] && str[i] != '%')
		++i;
	if (i)
		write(1, str, i);
	return (i);
}

int		ft_printf(const char *format, ...)
{
	va_list		ap;
	int			len;
	int			i;

	len = 0;
	va_start(ap, format);
	while (1)
	{
		i = print_plain(format);
		len += i;
		format += i;
		if (*format == '%')
			++format;
		else
			break ;
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
/*
int		main(void)
{
	int		i;

	i = ft_printf("AB%dCD%sEF%dGH%IJ\n", 12, "opqrst", 34);
	ft_printf("%d\n", i);
	return (0);
}
*/
