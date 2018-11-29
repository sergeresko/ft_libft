/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_integer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 16:51:02 by syeresko          #+#    #+#             */
/*   Updated: 2018/11/28 21:23:30 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include <inttypes.h>
#include <limits.h>

#include <unistd.h>		// for write

int			ft_print_integer(const t_fmt *f, intmax_t num)
{
	char	*s;
	int		n_sign;
	int		n_zeroes;
	int		n_digits;
	int		val_len;

//	s = pf_itoa_base(f, num == LLONG_MIN ? (uintmax_t)num : pf_abs(num), 10);
	if (num == LLONG_MIN)											//
		s = pf_itoa_base(f, (uintmax_t)num, 10);					//
	else															//
		s = pf_itoa_base(f, (uintmax_t)(num < 0 ? -num : num), 10);	//
//	s = ft_integer_s(num);
	n_digits = ft_strlen(s);
	n_sign = (num < 0 || f->plus || f->blank);		//
	n_zeroes = count_zeroes(f, n_sign, n_digits);
	val_len = n_sign + n_zeroes + n_digits;

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
