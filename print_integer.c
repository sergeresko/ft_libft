/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_integer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 16:51:02 by syeresko          #+#    #+#             */
/*   Updated: 2018/11/23 19:33:51 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

#include <unistd.h>		// for write in ft_print_integer




char	*ft_integer_s(long long num)
{
	char	*s;

	s = PF_BUF_END;
	*s = '\0';
	if (num < 0)
		num *= -1;	// TODO: -9223372036854775808 is not handled
	while (num)
	{
		*(--s) = '0' + num % 10;
		num /= 10;
	}
	return (s);
}

int		count_zeroes(const t_fmt *f, int n_sign, int n_digits)
{
	/*
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
	*/
	if (f->prec >= 0)
		return (ft_max(0, f->prec - n_digits));
	if (f->zero && !f->left)
		return (ft_max(0, f->width - n_digits - n_sign));
	return (n_digits == 0);
}

int		ft_print_integer(const t_fmt *f, long long num)
{
	char	*s;
	int		n_sign;
	int		n_zeroes;
	int		n_digits;
	int		val_len;

	s = ft_integer_s(num);
	n_digits = ft_strlen(s);
	n_sign = (num < 0 || f->plus || f->blank);
	n_zeroes = count_zeroes(f, n_sign, n_digits);
	val_len = n_sign + n_zeroes + n_digits;

	if (!f->left && (!f->zero || f->prec >= 0))
		ft_putnchar(' ', f->width - val_len);
	if (num < 0)
		ft_putchar('-');
	else if (f->plus)
		ft_putchar('+');
	else if (f->blank)
		ft_putchar(' ');
	ft_putnchar('0', n_zeroes);
	write(1, s, n_digits);		//	OR ft_putstr(s);
	if (f->left)
		ft_putnchar(' ', f->width - val_len);
	return (ft_max(f->width, val_len));
}
