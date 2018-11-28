/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_octal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 20:18:30 by syeresko          #+#    #+#             */
/*   Updated: 2018/11/28 18:53:19 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include <inttypes.h>

#include <unistd.h>		// for write in ft_print_octal



char	*ft_octal_s(uintmax_t num)
{
	char	*s;

	s = PF_BUF_END;
	*s = '\0';
	while (num)
	{
		*(--s) = '0' + (num & 7);
		num >>= 3;
	}
	return (s);
}

/*
static int	count_zeroes_o(const t_fmt *f, int n_digits)
{
	int		min_zeroes;

	min_zeroes = (f->alt == 1);
	if (f->prec >= 0)
		return (ft_max(min_zeroes, f->prec - n_digits));
	if (f->zero && !f->left)
		return (ft_max(min_zeroes, f->width - n_digits));
	return (ft_max(min_zeroes, (n_digits == 0)));
//	return ((n_digits == 0) ? 1 : min_zeroes);
}

int			ft_print_octal(const t_fmt *f, uintmax_t num)
{
	char	*s;
	int		n_zeroes;
	int		n_digits;
	int		val_len;

	s = ft_octal_s(num);
	n_digits = ft_strlen(s);
	n_zeroes = count_zeroes_o(f, n_digits);
	val_len = n_zeroes + n_digits;

	if (!f->left && (!f->zero || f->prec >= 0))
		ft_putnchar(' ', f->width - val_len);
	ft_putnchar('0', n_zeroes);
	write(1, s, n_digits);		//	OR ft_putstr(s);
	if (f->left)
		ft_putnchar(' ', f->width - val_len);
	return (ft_max(f->width, val_len));
}
*/

static int	count_zeroes(const t_fmt *f, int n_prefix, int n_digits)
{
	if (f->prec >= 0)
		return (ft_max(0, f->prec - n_digits));
	if (f->zero && !f->left)
		return (ft_max((n_digits == 0), f->width - n_prefix - n_digits));
	return (n_digits == 0);
}

int			ft_print_octal(const t_fmt *f, uintmax_t num)
{
	char	*s;
	int		n_prefix;
	int		n_zeroes;
	int		n_digits;
	int		val_len;

	s = ft_octal_s(num);
	n_digits = ft_strlen(s);
	if (f->prec <= n_digits)
		n_prefix = (f->alt == 1);// || (f->prec > n_digits) || (n_digits == 0 && f->prec == -1);
	else
		n_prefix = 0;
	n_zeroes = count_zeroes(f, n_prefix, n_digits);
	if (n_zeroes == 1 && n_prefix && n_digits == 0)
		n_zeroes = 0;
	val_len = n_prefix + n_zeroes + n_digits;

	if (!f->left && (!f->zero || f->prec >= 0))
		ft_putnchar(' ', f->width - val_len);
	if (n_prefix)
		write(1, "0", 1);		//
	ft_putnchar('0', n_zeroes);
	write(1, s, n_digits);		//	OR ft_putstr(s);
	if (f->left)
		ft_putnchar(' ', f->width - val_len);
	return (ft_max(f->width, val_len));
}
