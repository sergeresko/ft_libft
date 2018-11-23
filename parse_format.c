/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 14:57:37 by syeresko          #+#    #+#             */
/*   Updated: 2018/11/22 18:36:46 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

/*
**		ft_parse_integer
**	Returns a non-negative number represented in the beginning of string *a_str
**	and shifts the pointer to the first non-digit character.
**	If the string doesn't start with a digit, returns -1.
*/

int		ft_parse_integer(const char **a_str)
{
	int			n;
	const char	*s;

	s = *a_str;
	if (!ft_isdigit(*s))
		return (-1);
	n = 0;
	while (ft_isdigit(*s))
	{
		n *= 10;
		n += *s - '0';
		++s;
	}
	*a_str = s;
	return (n);
}

/*
**		ft_parse_flags
*/

void	ft_parse_flags(t_fmt *f, const char **a_str)
{
	char		c;
	
	while ((c = **a_str))
	{
		if (c == '#')
			f->alt = 1;
		else if (c == '0')
			f->zero = 1;
		else if (c == '-')
			f->left = 1;
		else if (c == ' ')
			f->blank = 1;
		else if (c == '+')
			f->plus = 1;
		else if (c == '\'')
			f->group = 1;
		else
			break ;
		++(*a_str);
	}
}

/*
**		ft_parse_width
**	Sets .width (and possibly .left) field to the value
**	specified in the initial portion of string *a_str
**	and shifts the pointer to the next character after the specification.
**	If the argument passed through '*' is negative, .left is set
**	and .width is set to the absolute value of the argument.
**	If no width is specified, .width isn't modified (default 0).
*/

void	ft_parse_width(t_fmt *f, const char **a_str, va_list ap)
{
	int			width;
	
	if (**a_str == '*')
	{
		width = va_arg(ap, int);
		++(*a_str);
	}
	else
		width = ft_parse_integer(a_str);
	if (width >= 0)
		f->width = width;
	else
	{
		f->left = 1;
		f->width = -width;
	}
}

/*
**		ft_parse_precision
**	Sets .prec field to the value specified in the initial portion
**	of string *a_str
**	and shifts the pointer to the next character after the specification.
**	If the specification doesn't start with '.', .prec is set to -1.
**	If the number after '.' is missing or if the agrument
**	passed through '*' is negative, .prec is set to 0.
**	TODO: update description.
*/

void	ft_parse_precision(t_fmt *f, const char **a_str, va_list ap)
{
	int			precision;

	if (**a_str == '*')
	{
		precision = va_arg(ap, int);
		++(*a_str);
	}
	else
		precision = ft_parse_integer(a_str);
	f->prec = ft_max(0, precision);
}

/*
**		ft_parse_modifier
**	Sets .mod field to the LAST value specified in the initial portion
**	of string *a_str
**	and shifts the pointer to the next chararcter after the specification.
**	A specification is considered a sequence of any length composed of "hlL".
**	Examples:
**		hlh  ->  MOD_H
**		llhL ->  MOD_L_CAPITAL
**		Lhh  ->  MOD_HH
*/

void	ft_parse_modifier(t_fmt *f, const char **a_str)
{
	char		c;
	t_modifier	m;

	while (1)
	{
		c = **a_str;
		m = f->mod;
		if (c == 'h')
			f->mod = (m == MOD_H || m == MOD_HH) ? MOD_HH : MOD_H;
		else if (c == 'l')
			f->mod = (m == MOD_L || m == MOD_LL) ? MOD_LL : MOD_L;
		else if (c == 'L')
			f->mod = MOD_L_CAPITAL;
		else
			break ;
		++(*a_str);
	}
}

/*
**		ft_parse_conversion
**	TODO
*/

void	ft_parse_conversion(t_fmt *f, const char **a_str)
{
	if ((f->conv = **a_str))
		++(*a_str);
}

/*
**		ft_parse_format
**	TODO
*/

void	ft_parse_format(t_fmt *a_fmt, const char **a_str, va_list ap)
{
	char		c;

	ft_bzero(a_fmt, sizeof(t_fmt));
	a_fmt->prec = -1;
	while ((c = **a_str) && !(a_fmt->conv))
	{
		if (ft_strchr(PF_FLAGS, c))
			ft_parse_flags(a_fmt, a_str);
		else if (ft_isdigit(c) || c == '*')
			ft_parse_width(a_fmt, a_str, ap);
		else if (c == '.')
		{
			++(*a_str);
			ft_parse_precision(a_fmt, a_str, ap);
		}
		else if (ft_strchr(PF_MODIFIERS, c))
			ft_parse_modifier(a_fmt, a_str);
		else if (ft_strchr(PF_CONVERSIONS, c))
			ft_parse_conversion(a_fmt, a_str);
		else
			++(*a_str);
	}
}
