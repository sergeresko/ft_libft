/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_octal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 20:18:30 by syeresko          #+#    #+#             */
/*   Updated: 2018/11/23 21:23:59 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

#include <unistd.h>		// for write in ft_print_integer


//	TODO: remake

#define OCTAL_BUF_SIZE 1024

char	*ft_octal_s(unsigned long long num)
{
	static char		buf[OCTAL_BUF_SIZE + 1];
	char			*s;

	s = buf + OCTAL_BUF_SIZE;
	*s = '\0';
	while (num)
	{
		*(--s) = '0' + (num & 7);
		num >>= 3;
	}
	return (s);
}

static int	count_zeroes_o(const t_fmt *a_fmt, int n_digits)
{
	int		min_zeroes;

	min_zeroes = (a_fmt->alternate == 1);
	if (a_fmt->precision >= 0)
		return (ft_max(min_zeroes, a_fmt->precision - n_digits));
	if (a_fmt->zero_padding && !a_fmt->left_align)
		return (ft_max(min_zeroes, a_fmt->width - n_digits));
	return (ft_max(min_zeroes, (n_digits == 0)));
}

int		ft_print_octal(const t_fmt *a_fmt, unsigned long long num)
{
	char	*s;
	int		n_zeroes;
	int		n_digits;
	int		val_len;

	s = ft_octal_s(num);
	n_digits = ft_strlen(s);
	n_zeroes = count_zeroes_o(a_fmt, n_digits);
	val_len = n_zeroes + n_digits;

	if (!a_fmt->left_align && (!a_fmt->zero_padding || a_fmt->precision >= 0))
		ft_putnchar(' ', a_fmt->width - val_len);
	ft_putnchar('0', n_zeroes);
	write(1, s, n_digits);		//	OR ft_putstr(s);
	if (a_fmt->left_align)
		ft_putnchar(' ', a_fmt->width - val_len);
	return ((a_fmt->width > val_len) ? a_fmt->width : val_len);
}
