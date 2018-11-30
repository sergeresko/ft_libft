/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_wctomb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 21:29:09 by syeresko          #+#    #+#             */
/*   Updated: 2018/11/30 14:53:04 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wchar.h>
#include "ft_printf.h"

char	*pf_wctomb(wchar_t wc)
{
	char	*s;
	char	mask;

	s = PF_BUF_END;
	*s = '\0';
	if (wc < 0200)
		*(--s) = wc;
	else
	{
		mask = 0200;
		while (wc > 0077)
		{
			*(--s) = 0200 | (wc & 0077);
			wc >>= 6;
			mask = 0200 | (mask >> 1);
		}
		*(--s) = mask | wc;
	}
	return (s);
}
