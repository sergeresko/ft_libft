/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 17:21:58 by syeresko          #+#    #+#             */
/*   Updated: 2018/12/03 13:12:25 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>		// needed ?
#include <inttypes.h>
#include <wchar.h>
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

intmax_t	get_arg_signed(const t_fmt *f, va_list ap)
{
	if (f->mod == MOD_HH)
		return ((char)va_arg(ap, int));
	if (f->mod == MOD_H)
		return ((short)va_arg(ap, int));
	if (f->mod == MOD_L)
		return (va_arg(ap, long));
	if (f->mod == MOD_LL)
		return (va_arg(ap, long long));
	if (f->mod == MOD_J)
		return (va_arg(ap, intmax_t));
	if (f->mod == MOD_Z)
		return (va_arg(ap, ssize_t));
	return (va_arg(ap, int));
}

uintmax_t	get_arg_unsigned(const t_fmt *f, va_list ap)
{
	if (f->mod == MOD_HH)
		return ((unsigned char)va_arg(ap, unsigned));
	if (f->mod == MOD_H)
		return ((unsigned short)va_arg(ap, unsigned));
	if (f->mod == MOD_L)
		return (va_arg(ap, unsigned long));
	if (f->mod == MOD_LL)
		return (va_arg(ap, unsigned long long));
	if (f->mod == MOD_J)
		return (va_arg(ap, uintmax_t));
	if (f->mod == MOD_Z)
		return (va_arg(ap, size_t));
	return (va_arg(ap, unsigned));
}

/*
**		ft_print_formatted
**	TODO
*/

int		ft_print_formatted(const char **a_str, va_list ap)
{
	t_fmt		fmt;

	ft_parse_format(&fmt, a_str, ap);
	//
	//
	//
	if (fmt.conv == 'd' || fmt.conv == 'i')
		return (ft_print_integer(&fmt, get_arg_signed(&fmt, ap)));
	if (fmt.conv == 'c')
		return ((fmt.mod == MOD_L) ?
				ft_print_wide_character(&fmt, (wchar_t)va_arg(ap, wint_t)) :
				ft_print_character(&fmt, (char)va_arg(ap, int)));
	if (fmt.conv == '%')
		return (ft_print_character(&fmt, '%'));
	if (fmt.conv == 's')
		return ((fmt.mod == MOD_L) ?
				ft_print_wide_string(&fmt, (wchar_t *)va_arg(ap, wint_t *)) :
				ft_print_string(&fmt, va_arg(ap, char *)));
	if (fmt.conv && ft_strchr("uoxXbB", fmt.conv))
	{
		uintmax_t	num;
		int			len;

		num = get_arg_unsigned(&fmt, ap);
		if (fmt.conv == 'u')
			len = ft_print_unsigned(&fmt, num);
		else if (fmt.conv == 'o')
			len = ft_print_octal(&fmt, num);
		else if (ft_strchr("bB", fmt.conv))
			len = ft_print_binary(&fmt, num);
		else									// if 'x' or 'X'
			len = ft_print_hexadecimal(&fmt, num);
		return (len);
	}
	if (fmt.conv == 'p')
		return (ft_print_pointer(&fmt, va_arg(ap, void *)));
	if (fmt.conv == 'f')
		return ((fmt.mod == MOD_L_CAPITAL) ?
				ft_print_float(&fmt, va_arg(ap, long double)) :
				ft_print_float(&fmt, va_arg(ap, double)));
	//
	//
	//
	ft_putstr("\e[32m{\n    flags:      \"");
	if (fmt.alt)
		ft_putchar('#');
	if (fmt.zero)
		ft_putchar('0');
	if (fmt.left)
		ft_putchar('-');
	if (fmt.blank)
		ft_putchar(' ');
	if (fmt.plus)
		ft_putchar('+');
	ft_putstr("\";\n    width:      ");
	ft_putnbr(fmt.width);
	ft_putstr(";\n    precision:  ");
	if (fmt.prec == PF_PREC_NONE)
		ft_putstr("NONE");
	else
		ft_putnbr(fmt.prec);
	ft_putstr(";\n    modifier:   ");
	if (fmt.mod == MOD_HH)
		ft_putstr("hh");
	else if (fmt.mod == MOD_H)
		ft_putstr("h");
	else if (fmt.mod == MOD_L)
		ft_putstr("l");
	else if (fmt.mod == MOD_LL)
		ft_putstr("ll");
	else if (fmt.mod == MOD_L_CAPITAL)
		ft_putstr("L");
	else
		ft_putstr("NONE");
	ft_putstr(";\n    conversion: ");
	if (fmt.conv)
		ft_putchar(fmt.conv);
	else
		ft_putstr("NONE");
	ft_putstr(";\n}\e[0m");
	if (fmt.conv && fmt.conv != '%')
		(void)va_arg(ap, int);
	return (1000);					//
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
