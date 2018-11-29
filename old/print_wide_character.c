/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_wide_character.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 17:48:44 by syeresko          #+#    #+#             */
/*   Updated: 2018/11/29 19:24:16 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <wchar.h>

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

#define BUF_SIZE 5
char	g_buf[BUF_SIZE];
#define BUF_START g_buf
#define BUF_END (g_buf + BUF_SIZE)

char	*unicode_to_utf8(wchar_t wc)
{
	char	*s;
	char	mask;

	s = BUF_END;
	*s = '\0';
	if (wc < 0200)
	{
		*(--s) = wc;
		return (s);
	}
	mask = 0200;
	while (wc > 0077)
	{
		*(--s) = 0200 | (wc & 0077);
		wc >>= 6;
		mask = 0200 | (mask >> 1);
	}
	*(--s) = mask | wc;
	return (s);
}

#include <locale.h>
#include <stdio.h>

int		main(void)
{
	int			res;
	wchar_t		wc = L'我';
//	wchar_t		wc = L'ф';
	char		*s;

	setlocale(LC_ALL, "en_US.UTF-8");
	res = print_wide_character(wc);
	printf("\n%d\n", res);
	s = unicode_to_utf8(wc);
	printf("%s\n", s);
	printf("%4lc\n", L'w');
	return (0);
}
