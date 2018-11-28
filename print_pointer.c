/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 20:18:34 by syeresko          #+#    #+#             */
/*   Updated: 2018/11/28 18:59:14 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include <inttypes.h>

#include <unistd.h>		// for write in ft_print_pointer



static char	*ft_pointer_s(uintmax_t num)
{
	char	*s;
	char	digit;

	s = PF_BUF_END;
	*s = '\0';
	while (num)
	{
		digit = num & 15;
		*(--s) = (digit < 10) ? ('0' + digit) : ('a' - 10 + digit);
		num >>= 4;
	}
	return (s);
}

int		ft_print_pointer(const t_fmt *f, void *ptr)
{
	char	*s;
	int		n_prefix;
	int		n_zeroes;
	int		n_digits;
	int		val_len;

	s = ft_pointer_s((uintmax_t)ptr);
	n_prefix = 2;
	n_digits = ft_strlen(s);
	n_zeroes = count_zeroes(f, n_prefix, n_digits);
	val_len = n_prefix + n_zeroes + n_digits;

	if (!f->left && (!f->zero || f->prec >= 0))
		ft_putnchar(' ', f->width - val_len);
	write(1, "0x", 2);			// OR:	ft_putstr("0x");
	ft_putnchar('0', n_zeroes);
	write(1, s, n_digits);		//	OR ft_putstr(s);
	if (f->left)
		ft_putnchar(' ', f->width - val_len);
	return (ft_max(f->width, val_len));
}
