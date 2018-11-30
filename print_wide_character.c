/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_wide_character.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 17:48:44 by syeresko          #+#    #+#             */
/*   Updated: 2018/11/30 12:43:02 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

#include <unistd.h>
#include <wchar.h>

/*
int		print_wide_character(wchar_t wc)
{
	char	s[4];
	int		i;

	i = 0;
	if (wc < 0x80)
		s[i++] = wc;
	else if (wc < 0x800)
	{
		s[i++] = 0xc0 | (wc >> 6);
		s[i++] = 0x80 | (0x3f & wc);
	}
	else if (wc < 0x10000)
	{
		s[i++] = 0xe0 | (wc >> 12);
		s[i++] = 0x80 | (0x3f & (wc >> 6));
		s[i++] = 0x80 | (0x3f & wc);
	}
	else
	{
		s[i++] = 0xf0 | (wc >> 18);
		s[i++] = 0x80 | (0x3f & (wc >> 12));
		s[i++] = 0x80 | (0x3f & (wc >> 6));
		s[i++] = 0x80 | (0x3f & wc);
	}
	write(1, s, i);
	return (i);
}
*/

int		ft_print_wide_character(const t_fmt *f, wchar_t wc)
{
	char	*s;
	int		n_bytes;

	s = pf_unicode_to_utf8(wc);
	n_bytes = ft_strlen(s);
	if (!f->left)
		ft_putnchar((f->zero) ? '0' : ' ', f->width - n_bytes);
	write(1, s, n_bytes);		// or ft_putstr(s);
	if (f->left)
		ft_putnchar(' ', f->width - n_bytes);
	return (ft_max(f->width, n_bytes));
}

/*
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

int		main(void)
{
	int			res;
	wchar_t		wc = L'我';
//	wchar_t		wc = L'ы';
	char		*s;

	setlocale(LC_ALL, "");
	printf("%d\n", MB_CUR_MAX);
	res = print_wide_character(wc);
	printf("\n%d\n", res);
	s = unicode_to_utf8(wc);
	printf("%s\n", s);
	printf("%4lc\n", L'我');
	printf("\n----\n");
	for (int i = 126; i < 300; ++i)
	{
		res = printf("%3d: %.2lc", i, i);
		printf("----(%d)\n", res);
	}
	return (0);
}
*/
