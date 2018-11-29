/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 17:05:38 by syeresko          #+#    #+#             */
/*   Updated: 2018/11/29 13:47:09 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include <inttypes.h>

#include <unistd.h>		// for write


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

int			ft_print_unsigned(const t_fmt *f, uintmax_t num)
{
	char	*s;
	int		n_prefix;
	int		n_zeroes;
	int		n_digits;
	int		val_len;

	s = pf_itoa_base(f, num);
	n_prefix = 0;										//
	n_digits = ft_strlen(s);
	n_zeroes = count_zeroes(f, n_prefix, n_digits);
	val_len = n_prefix + n_zeroes + n_digits;

	if (!f->left && !(f->zero && f->prec == PF_PREC_NONE))
		ft_putnchar(' ', f->width - val_len);
	ft_putnchar('0', n_zeroes);
	write(1, s, n_digits);		//	OR ft_putstr(s);
	if (f->left)
		ft_putnchar(' ', f->width - val_len);
	return (ft_max(f->width, val_len));
}
