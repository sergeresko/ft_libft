/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 17:14:38 by syeresko          #+#    #+#             */
/*   Updated: 2018/11/29 16:18:51 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <inttypes.h>

# define	PF_FLAGS		"#0- +\'"
# define	PF_MODIFIERS	"hljzL"
# define	PF_CONVERSIONS	"cspdibBouxXfk%"

typedef enum	e_modifier
{
	MOD_NONE = 0,
	MOD_HH,
	MOD_H,
	MOD_L,
	MOD_LL,
	MOD_J,
	MOD_Z,
	MOD_L_CAPITAL
}				t_modifier;

typedef struct	s_fmt
{
	int			width;
	int			prec;
//	char		flags[8];
	unsigned	alt: 1;
	unsigned	zero: 1;
	unsigned	left: 1;
	unsigned	blank: 1;
	unsigned	plus: 1;
	unsigned	group: 1;
	unsigned	capital: 1;		//	needed ?
	t_modifier	mod;
	char		conv;
	unsigned	base;			//	needed ?
}				t_fmt;

# define PF_PREC_NONE (-1)




# define PF_RESET "\e[0m"
# define PF_RED "\e[31m"
# define PF_GREEN "\e[32m"
# define PF_YELLOW "\e[33m"
# define PF_BLUE "\e[34m"
# define PF_MAGENTA "\e[35m"
# define PF_CYAN "\e[36m"

















//void	ft_print_repeated(char c, int times);

# define PF_BUF_SIZE 1024
char	g_pf_buf[PF_BUF_SIZE + 1];
# define PF_BUF_START g_pf_buf
# define PF_BUF_END (g_pf_buf + PF_BUF_SIZE)


char	*pf_itoa_base(const t_fmt *f, uintmax_t num);
int		count_zeroes(const t_fmt *f, int n_prefix, int n_digits);


int		ft_print_character(const t_fmt *a_fmt, char c);
int		ft_print_string(const t_fmt *a_fmt, const char *str);

int		ft_print_integer(const t_fmt *a_fmt, intmax_t num);

int		ft_print_unsigned(const t_fmt *a_fmt, uintmax_t num);
int		ft_print_hexadecimal(const t_fmt *a_fmt, uintmax_t num);
int		ft_print_octal(const t_fmt *a_fmt, uintmax_t num);
int		ft_print_binary(const t_fmt *a_fmt, uintmax_t num);

int		ft_print_pointer(const t_fmt *a_fmt, void *ptr);





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
