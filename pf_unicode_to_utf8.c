/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_unicode_to_utf8.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 21:29:09 by syeresko          #+#    #+#             */
/*   Updated: 2018/11/30 12:42:34 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wchar.h>
#include "ft_printf.h"

char	*pf_unicode_to_utf8(wchar_t wc)
{
	char	*s;
	char	mask;

	s = PF_BUF_END;
	*s = '\0';
	if (wc < '\200')
		*(--s) = wc;
	else
	{
		mask = '\200';
		while (wc > '\077')
		{
			*(--s) = '\200' | (wc & '\077');
			wc >>= 6;
			mask = '\200' | (mask >> 1);
		}
		*(--s) = mask | wc;
	}
	return (s);
}
