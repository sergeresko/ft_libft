/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexadecimal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 12:32:19 by syeresko          #+#    #+#             */
/*   Updated: 2018/11/28 18:58:31 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include <inttypes.h>

#include <unistd.h>		// for write in ft_print_hexadecimal



static char	*ft_hexadecimal_s(const t_fmt *f, uintmax_t num)
{
	char	*s;
	char	digit;
	char	letter_a;

	letter_a = (f->conv == 'x') ? 'a' : 'A';
	s = PF_BUF_END;
	*s = '\0';
	while (num)
	{
		digit = num & 15;
		*(--s) = (digit < 10) ? ('0' + digit) : (letter_a + digit - 10);
		num >>= 4;
	}
	return (s);
}

int		ft_print_hexadecimal(const t_fmt *f, uintmax_t num)
{
	char	*s;
	int		n_prefix;
	int		n_zeroes;
	int		n_digits;
	int		val_len;

	s = ft_hexadecimal_s(f, num);
	n_prefix = (num != 0 && f->alt == 1) ? 2 : 0;	// = (num && f->alt) ? 2 : 0
	n_digits = ft_strlen(s);
	n_zeroes = count_zeroes(f, n_prefix, n_digits);
	val_len = n_prefix + n_zeroes + n_digits;

	if (!f->left && (!f->zero || f->prec >= 0))
		ft_putnchar(' ', f->width - val_len);
	if (n_prefix)		// OR:	if (f->alt)
		write(1, f->conv == 'x' ? "0x" : "0X", 2);
// OR:	ft_putstr(f->conv == 'x' ? "0x" : "0X");
	ft_putnchar('0', n_zeroes);
	write(1, s, n_digits);		//	OR ft_putstr(s);
	if (f->left)
		ft_putnchar(' ', f->width - val_len);
	return (ft_max(f->width, val_len));
}
