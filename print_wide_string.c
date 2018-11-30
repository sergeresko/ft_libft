/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_wide_string.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 12:46:10 by syeresko          #+#    #+#             */
/*   Updated: 2018/11/30 15:55:24 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"		//	?
#include "ft_printf.h"

#include <wchar.h>

/*
int		ft_utf8_len(const wchar_t *wstr)
{
	int			len;
	wchar_t		wc;

	len = 0;
	while ((wc = *wstr))
	{
		if (wc < 0x80)
			len += 1;
		else if (wc < 0x800)
			len += 2;
		else if (wc < 0x10000)
			len += 3;
		else
			len += 4;
		++wstr;
	}
	return (len);
}
*/

int		ft_utf8_len(wchar_t wc)
{
	if (wc < 0x80)
		return (1);
	if (wc < 0x800)
		return (2);
	if (wc < 0x10000)
		return (3);
	return (4);
}

int		ft_print_wide_string(const t_fmt *f, const wchar_t *wstr)
{
	const wchar_t	null_msg[] = L"(null)";
	int				n_wchars;
	int				n_bytes;
	int				wlen;

	if (!wstr)
		wstr = null_msg;
	n_wchars = 0;
	n_bytes = 0;
	while (wstr[n_wchars])
	{
		wlen = ft_utf8_len(wstr[n_wchars]);
		if (f->prec != PF_PREC_NONE && n_bytes + wlen > f->prec)
			break ;
		n_bytes += wlen;
		++n_wchars;
	}
	if (!f->left)
		ft_putnchar((f->zero) ? '0' : ' ', f->width - n_bytes);
	while (n_wchars--)
		ft_putstr(pf_wctomb(*(wstr++)));
	if (f->left)
		ft_putnchar(' ', f->width - n_bytes);
	return (ft_max(f->width, n_bytes));
}
