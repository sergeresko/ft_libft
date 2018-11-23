/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 17:05:38 by syeresko          #+#    #+#             */
/*   Updated: 2018/11/23 17:59:16 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

#include <unistd.h>		// for write in ft_print_integer


//	TODO: remake

#define UNSIGNED_BUF_SIZE 1024

char	*ft_unsigned_s(const t_fmt *a_fmt, unsigned long long num)
{
	static char		buf[UNSIGNED_BUF_SIZE + 1];
	char			*s;
	const char		digits_small[] = "0123456789abcdef";
	const char		digits_capital[] = "0123456789ABCDEF";
	char			*digits;
	int				base;

	s = buf + UNSIGNED_BUF_SIZE;
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

int		count_zeroes(const t_fmt *a_fmt, int n_sign, int n_digits)
{
//	if (a_fmt->precision is given)
	if (a_fmt->precision >= 0)
	{
		if (a_fmt->precision > n_digits)
			return (a_fmt->precision - n_digits);
	}
	else if (a_fmt->zero_padding && !a_fmt->left_align)
	{
		if (a_fmt->width > n_digits)
			return (a_fmt->width - n_digits - n_sign);
	}
	else if (n_digits == 0)
		return (1);
	return (0);
}

int		ft_print_unsigned(const t_fmt *a_fmt, unsigned long long num)
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
