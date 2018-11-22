/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 17:14:38 by syeresko          #+#    #+#             */
/*   Updated: 2018/11/22 20:36:43 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

# define	PF_FLAGS		"#0- +\'"
# define	PF_MODIFIERS	"hlL"
# define	PF_CONVERSIONS	"cspdibouxXfk%"

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







void	ft_print_repeated(char c, int times);

//	#define INT_BUF_SIZE 1024

char	*ft_integer_s(int num);
int		count_zeroes(const t_fmt *a_fmt, int n_sign, int n_digits);
int		ft_print_integer(const t_fmt *a_fmt, int num);




int		ft_parse_integer(const char **a_str);

void	ft_parse_flags(t_fmt *a_fmt, const char **a_str);
void	ft_parse_width(t_fmt *a_fmt, const char **a_str, va_list ap);
void	ft_parse_precision(t_fmt *a_fmt, const char **a_str, va_list ap);
void	ft_parse_modifier(t_fmt *a_fmt, const char **a_str);
void	ft_parse_conversion(t_fmt *a_fmt, const char **a_str);		// needed ?
void	ft_parse_format(t_fmt *a_fmt, const char **a_str, va_list ap);

int		ft_print_plain(const char **a_str);
int		ft_print_formatted(const char **a_str, va_list ap);

int		ft_printf(const char *format, ...);

#endif
