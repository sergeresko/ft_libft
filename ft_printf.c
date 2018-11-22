/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 17:21:58 by syeresko          #+#    #+#             */
/*   Updated: 2018/11/22 18:50:00 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include "libft.h"
#include "ft_printf.h"

/*
**		ft_print_plain
**	Prints the initial portion of string *a_str to stdout
**	until '\0' or '%' is encountered,
**	shifts the pointer to this stop-character
**	and returns the number of printed characters.
*/

int		ft_print_plain(const char **a_str)
{
	const char	*s;
	int			len;

	s = *a_str;
	len = 0;
	while (s[len] && s[len] != '%')
		++len;
	if (len)
		write(1, s, len);
	*a_str += len;
	return (len);
}

/*
**		ft_print_formatted
**	TODO
*/

int		ft_print_formatted(const char **a_str, va_list ap)
{
	t_fmt		fmt;
	int			len;

	ft_parse_format(&fmt, a_str, ap);
	//
	// Test:
	if (fmt.conversion == 'd' || fmt.conversion == 'i')
		len = ft_print_integer(&fmt, va_arg(ap, int));
	else
	{




	ft_putstr("\e[32m{\n    flags:      \"");
	if (fmt.alternate)
		ft_putchar('#');
	if (fmt.zero_padding)
		ft_putchar('0');
	if (fmt.left_align)
		ft_putchar('-');
	if (fmt.blank)
		ft_putchar(' ');
	if (fmt.plus)
		ft_putchar('+');
	ft_putstr("\";\n    width:      ");
	ft_putnbr(fmt.width);
	ft_putstr(";\n    precision:  ");
	if (fmt.precision == -1)
		ft_putstr("NONE");
	else
		ft_putnbr(fmt.precision);
	ft_putstr(";\n    modifier:   ");
	if (fmt.modifier == MOD_HH)
		ft_putstr("hh");
	else if (fmt.modifier == MOD_H)
		ft_putstr("h");
	else if (fmt.modifier == MOD_L)
		ft_putstr("l");
	else if (fmt.modifier == MOD_LL)
		ft_putstr("ll");
	else if (fmt.modifier == MOD_L_CAPITAL)
		ft_putstr("L");
	else
		ft_putstr("NONE");
	ft_putstr(";\n    conversion: ");
	if (fmt.conversion)
		ft_putchar(fmt.conversion);
	else
		ft_putstr("NONE");
	ft_putstr(";\n}\e[0m");
	if (fmt.conversion && fmt.conversion != '%')
		(void)va_arg(ap, int);
	len = 1000;


	}
	//
	//
	return (len);					//
}

/*
**	ft_printf
*/

int		ft_printf(const char *format, ...)
{
	va_list		ap;
	int			len;

	va_start(ap, format);
	len = 0;
	while (1)
	{
		len += ft_print_plain(&format);
		if (*format == '\0')
			break ;
		++format;
		len += ft_print_formatted(&format, ap);
	}
	va_end(ap);
	return (len);
}
