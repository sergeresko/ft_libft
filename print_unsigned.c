/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 17:05:38 by syeresko          #+#    #+#             */
/*   Updated: 2018/11/24 13:33:28 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

#include <unistd.h>		// for write in ft_print_integer


//	TODO: remake
/*
static char	*ft_unsigned_s(const t_fmt *a_fmt, unsigned long long num)
{
	char			*s;
	const char		digits_small[] = "0123456789abcdef";
	const char		digits_capital[] = "0123456789ABCDEF";
	char			*digits;
	int				base;

	s = PF_BUF_END;
	*s = '\0';
	if (ft_strchr("bB", a_fmt->conversion))
		base = 2;
	else if (a_fmt->conversion == 'o')
		base = 8;
	else if (a_fmt->conversion == 'u')
		base = 10;
	else if (ft_strchr("xX", a_fmt->conversion))
		base = 16;
	else
		return (s);
	digits = (ft_strchr("BX", a_fmt->conversion)) ? digits_capital : digits_small;
	while (num)
	{
		*(--s) = digits[num % base];
		num /= base;
	}
	return (s);
}
*/

static char	*ft_unsigned_s(unsigned long long num)
{
	char	*s;

	s = PF_BUF_END;
	*s = '\0';
	while (num)
	{
		*(--s) = '0' + num % 10;
		num /= 10;
	}
	return (s);
}

static int	count_zeroes_u(const t_fmt *f, int n_digits)
{
	if (f->prec >= 0)
		return (ft_max(0, f->prec - n_digits));
	if (f->zero && !f->left)
		return (ft_max(0, f->width - n_digits));
	return (n_digits == 0);
}

/*
int			ft_print_unsigned(const t_fmt *a_fmt, unsigned long long num)
{
	char	*s;
	int		n_prefix;
	int		n_zeroes;
	int		n_digits;
	int		val_len;

	s = ft_unsigned_s(num);
	n_digits = ft_strlen(s);
	n_prefix = (num && a_fmt->alternate && ft_strchr("bBxX", a_fmt->conversion)) ? 2 : 0;
	n_zeroes = count_zeroes(a_fmt, n_sign, n_digits);
	val_len = n_sign + n_zeroes + n_digits;

	if (!a_fmt->left_align && (!a_fmt->zero_padding || a_fmt->precision >= 0))
		ft_putnchar(' ', a_fmt->width - val_len);
	if (num < 0)
		ft_putchar('-');
	else if (a_fmt->plus)
		ft_putchar('+');
	else if (a_fmt->blank)
		ft_putchar(' ');
	ft_putnchar('0', n_zeroes);
	write(1, s, n_digits);		//	OR ft_putstr(s);
	if (a_fmt->left_align)
		ft_putnchar(' ', a_fmt->width - val_len);
	return ((a_fmt->width > val_len) ? a_fmt->width : val_len);
}
*/

int			ft_print_unsigned(const t_fmt *f, unsigned long long num)
{
	char	*s;
	int		n_zeroes;
	int		n_digits;
	int		val_len;

	s = ft_unsigned_s(num);
	n_digits = ft_strlen(s);
	n_zeroes = count_zeroes_u(f, n_digits);
	val_len = n_zeroes + n_digits;

	if (!f->left && (!f->zero || f->prec >= 0))
		ft_putnchar(' ', f->width - val_len);
	ft_putnchar('0', n_zeroes);
	write(1, s, n_digits);		//	OR ft_putstr(s);
	if (f->left)
		ft_putnchar(' ', f->width - val_len);
	return (ft_max(f->width, val_len));
}
