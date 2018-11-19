/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 14:57:37 by syeresko          #+#    #+#             */
/*   Updated: 2018/11/18 16:48:35 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct	s_specification
{
	int			min_width;
	int			precision;
	unsigned	alternate:1;
	unsigned	zero_padding:1;
	unsigned	left_adjust:1;
	unsigned	sign_blank:1;
	unsigned	sign_plus:1;
	unsigned	capital:1;
	char		size;
	char		conversion;
}				t_specification;

int		

/*
typedef struct	s_flag
{
	char		symbol;
	unsigned	mask;
}				t_flag;

t_flag			array[] =
{
	{'#', 1},
	{'0', 2},
	{'-', 4},
	{' ', 8},
	{'+', 16},
	{'\0', 0},
};
*/

/*
unsigned	parse_flags(const char *s)
{
	unsigned	flags;

	flags = 0;
	while (*s == '#' || *s == '0' || *s == '-' || *s == ' ' || *s == '+')
	{
		i = 0;
		while ((c = array[i].symbol))
		{
			if (c == *s)
			{
				flags |= array[i].mask;
				break;
			}
			++i;
		}
		++s;
	}
	return (flags);
}
*/

		parse_flags(const char **a_fmt)
{
	const char	*s;
	int			i;

	s = *a_fmt;
	i = 0;
	while (1)
	{
		if (s[i] == '#')
			fmt.alternate = 1;
		else if (s[i] == '0')
			fmt.zero_padding = 1;
	}
	while (ft_strchr("#0- +'", s[i]))
	return
}

int		parse_width(const char *s)
{
	int		width;

	width = 0;
	while ('0' <= *s && *s <= '9')
	{
		width = width * 10 + (*s - '0');
		++s;
	}
	return (width);
}

int		parse_precision(const char *s)
{
	int		precision;

	if (*s != '.')
		return (0);			// ?
	while ('0' <= *s && *s <= '9')
	{
		precision = precision * 10 + (*s - '0');
		++s;
	}
	return (precision);
}

int		parse(const char *s)
{
	int		len;

	len = 0;
	while (
		if (*s == '-'
	parse_flags();
	parse_width();
	parse_precision();
	parse_type();
	return (len);
}
