/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_integer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 16:51:02 by syeresko          #+#    #+#             */
/*   Updated: 2018/11/29 15:39:34 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include <inttypes.h>

#include <unistd.h>		// for write

int			ft_print_integer(const t_fmt *f, intmax_t num)
{
	char	*s;
	int		n_prefix;
	int		n_zeroes;
	int		n_digits;
	int		val_len;

	s = pf_itoa_base(f, num < 0 ? -num : num);		//
	n_digits = ft_strlen(s);
	n_prefix = (num < 0 || f->plus || f->blank);	//
	n_zeroes = count_zeroes(f, n_prefix, n_digits);
	val_len = n_prefix + n_zeroes + n_digits;
	if (!f->left && !(f->zero && f->prec == PF_PREC_NONE))
		ft_putnchar(' ', f->width - val_len);
	if (num < 0)									//
		ft_putchar('-');							//
	else if (f->plus)								//
		ft_putchar('+');							//
	else if (f->blank)								//
		ft_putchar(' ');							//
	ft_putnchar('0', n_zeroes);
	write(1, s, n_digits);		//	OR ft_putstr(s);
	if (f->left)
		ft_putnchar(' ', f->width - val_len);
	return (ft_max(f->width, val_len));
}
