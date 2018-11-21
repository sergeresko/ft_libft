#include <stdarg.h>
#include <unistd.h>

#include "libft.h"

#define	PF_FLAGS "#0- +\'"
#define PF_MODIFIERS "hlL"
#define PF_CONVERSIONS "cspdibouxXfk%"

/*
int		unsigned_long(char *str, unsigned long n)
{
	int		len;

	len = 0;
	while (n)
	{
		*(--str) = '0' + n % a_fmt->base;
		n /= a_fmt->base;
		++len;
	}
	return (len);
}
*/

typedef enum	e_modifier{
	MOD_NONE = 0,
	MOD_HH,
	MOD_H,
	MOD_L,
	MOD_LL,
	MOD_L_CAPITAL
}				t_modifier;

typedef struct	s_fmt
{
	int			width;
	int			precision;
//	char		flags[8];
	unsigned	alternate: 1;
	unsigned	zero_padding: 1;
	unsigned	left_align: 1;
	unsigned	blank: 1;
	unsigned	plus: 1;
	unsigned	grouping: 1;
	unsigned	capital: 1;		//	needed ?
	t_modifier	modifier;
	char		conversion;
	unsigned	base;			//	needed ?
}				t_fmt;

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
	if (*s < '0' || *s > '9')
		return (-1);
	n = 0;
	while ('0' <= *s && *s <= '9')
	{
		n *= 10;
		n += *s - '0';
		++s;
	}
	*a_str = s;
	return (n);
}

/*
**		old_ft_parse_flags
**	NO MORE NEEDED
*/
/*
void	old_ft_parse_flags(t_fmt *a_fmt, const char **a_str)
{
	char		c;

	c = **a_str;
	while (ft_strchr(FT_PRINTF_FLAGS, c))
	{
		if (!ft_strchr(a_fmt->flags, c))
			a_fmt->flags[ft_strlen(a_fmt->flags)] = c;
		++(*a_str);
		c = **a_str;
	}
}
*/

/*
**		ft_parse_flags
*/

void	ft_parse_flags(t_fmt *a_fmt, const char **a_str)
{
	char		c;
	
	while ((c = **a_str))
	{
		if (c == '#')
			a_fmt->alternate = 1;
		else if (c == '0')
			a_fmt->zero_padding = 1;
		else if (c == '-')
			a_fmt->left_align = 1;
		else if (c == ' ')
			a_fmt->blank = 1;
		else if (c == '+')
			a_fmt->plus = 1;
		else if (c == '\'')
			a_fmt->grouping = 1;
		else
			break ;
		++(*a_str);
	}
}

/*
**		ft_parse_width
**	Sets .width (and possibly .left_align) field to the value
**	specified in the initial portion of string *a_str
**	and shifts the pointer to the next character after the specification.
**	If the argument passed through '*' is negative, .left_align is set
**	and .width is set to the absolute value of the argument.
**	If no width is specified, .width isn't modified (default 0).
*/

void	ft_parse_width(t_fmt *a_fmt, const char **a_str, va_list ap)
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
		a_fmt->width = width;
	else
	{
		a_fmt->left_align = 1;
		a_fmt->width = -width;
	}
}

/*
**		ft_parse_precision
**	Sets .precision field to the value specified in the initial portion
**	of string *a_str
**	and shifts the pointer to the next character after the specification.
**	If the specification doesn't start with '.', .precision is set to -1.
**	If the number after '.' is missing or if the agrument
**	passed through '*' is negative, .precision is set to 0.
*/

void	ft_parse_precision(t_fmt *a_fmt, const char **a_str, va_list ap)
{
	int			precision;

	if (**a_str == '*')
	{
		precision = va_arg(ap, int);
		++(*a_str);
	}
	else
		precision = ft_parse_integer(a_str);
	if (precision >= 0)
		a_fmt->precision = precision;
}

/*
**		ft_parse_modifier
**	Sets .modifier field to the LAST value specified in the initial portion
**	of string *a_str
**	and shifts the pointer to the next chararcter after the specification.
**	A specification is considered a sequence of any length composed of "hlL".
**	Examples:
**		hlh  ->  MOD_H
**		llhL ->  MOD_L_CAPITAL
**		Lhh  ->  MOD_HH
*/

void	ft_parse_modifier(t_fmt *a_fmt, const char **a_str)
{
	char		c;
	t_modifier	m;

	while (1)
	{
		c = **a_str;
		m = a_fmt->modifier;
		if (c == 'h')
			a_fmt->modifier = (m == MOD_H || m == MOD_HH) ? MOD_HH : MOD_H;
		else if (c == 'l')
			a_fmt->modifier = (m == MOD_L || m == MOD_LL) ? MOD_LL : MOD_L;
		else if (c == 'L')
			a_fmt->modifier = MOD_L_CAPITAL;
		else
			break ;
		++(*a_str);
	}
}

/*
**		ft_parse_conversion
**	TODO
*/

void	ft_parse_conversion(t_fmt *a_fmt, const char **a_str)
{
	if ((a_fmt->conversion = **a_str))
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
	a_fmt->precision = -1;
	while ((c = **a_str) && !(a_fmt->conversion))
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

	ft_parse_format(&fmt, a_str, ap);
	//
	// Test:
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
	//
	//
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

int		main(void)
{
	int		i;

	i = ft_printf("abc%+08.3fABC%%%-*d", 3.14, 555, 42);
	ft_putstr("\e[31m(length = ");
	ft_putnbr(i);
	ft_putstr(")\e[0m\n");
	return (0);
}
