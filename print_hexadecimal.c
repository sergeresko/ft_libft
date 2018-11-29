/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexadecimal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 12:32:19 by syeresko          #+#    #+#             */
/*   Updated: 2018/11/28 21:25:12 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include <inttypes.h>

#include <unistd.h>		// for write

int		ft_print_hexadecimal(const t_fmt *f, uintmax_t num)
{
	char	*s;
	int		n_prefix;
	int		n_zeroes;
	int		n_digits;
	int		val_len;

	s = pf_itoa_base(f, num, 16);
	n_prefix = (num != 0 && f->alt == 1) ? 2 : 0;	// = (f->alt && num) ? 2 : 0
	n_digits = ft_strlen(s);
	n_zeroes = count_zeroes(f, n_prefix, n_digits);
	val_len = n_prefix + n_zeroes + n_digits;

	if (!f->left && !(f->zero && f->prec == PF_PREC_NONE))
		ft_putnchar(' ', f->width - val_len);
	if (n_prefix)		// OR:	if (f->alt == 1)		//
		write(1, f->conv == 'x' ? "0x" : "0X", 2);		//
// OR:	ft_putstr(f->conv == 'x' ? "0x" : "0X");		//
	ft_putnchar('0', n_zeroes);
	write(1, s, n_digits);		//	OR ft_putstr(s);
	if (f->left)
		ft_putnchar(' ', f->width - val_len);
	return (ft_max(f->width, val_len));
}
