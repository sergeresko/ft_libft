/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_octal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 20:18:30 by syeresko          #+#    #+#             */
/*   Updated: 2018/11/29 13:46:59 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include <inttypes.h>

#include <unistd.h>		// for write

int			ft_print_octal(const t_fmt *f, uintmax_t num)
{
	char	*s;
	int		n_prefix;
	int		n_zeroes;
	int		n_digits;
	int		val_len;

	s = pf_itoa_base(f, num);
	n_digits = ft_strlen(s);
	n_prefix = (f->alt && n_digits >= f->prec) ? 1 : 0;		//
//	n_prefix = (n_digits < f->prec) ? 0 : (f->alt == 1);	//	old
	n_zeroes = count_zeroes(f, n_prefix, n_digits);
	if (n_zeroes == 1 && n_prefix && n_digits == 0)			//
		n_zeroes = 0;										//
	val_len = n_prefix + n_zeroes + n_digits;

	if (!f->left && !(f->zero && f->prec == PF_PREC_NONE))
		ft_putnchar(' ', f->width - val_len);
	if (n_prefix)												//
		write(1, "0", 1);		//	OR ft_putstr("0");			//
	ft_putnchar('0', n_zeroes);
	write(1, s, n_digits);		//	OR ft_putstr(s);
	if (f->left)
		ft_putnchar(' ', f->width - val_len);
	return (ft_max(f->width, val_len));
}
