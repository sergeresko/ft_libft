/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 21:13:49 by syeresko          #+#    #+#             */
/*   Updated: 2018/11/29 13:50:18 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include <inttypes.h>

char	*pf_itoa_base(const t_fmt *f, uintmax_t num)
{
	unsigned	base;
	char		letter_a;
	char		*s;
	char		digit;

	base = 10;
	if (ft_strchr("xXp", f->conv))
		base = 16;
	else if (f->conv == 'o')
		base = 8;
	else if (ft_strchr("bB", f->conv))
		base = 2;
	letter_a = (f->conv == 'X') ? 'A' : 'a';
	s = PF_BUF_END;
	*s = '\0';
	while (num)
	{
		digit = num % base;
		*(--s) = digit + ((digit < 10) ? '0' : (letter_a - 10));
		num /= base;
	}
	return (s);
}
