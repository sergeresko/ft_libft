/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_character.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 12:41:52 by syeresko          #+#    #+#             */
/*   Updated: 2018/11/23 13:25:31 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int		ft_print_character(const t_fmt *a_fmt, char c)
{
	if (!a_fmt->left_align)
		ft_putnchar((a_fmt->zero_padding) ? '0' : ' ', a_fmt->width - 1);
	ft_putchar(c);
	if (a_fmt->left_align)
		ft_putnchar(' ', a_fmt->width - 1);
	return ((a_fmt->width > 1) ? a_fmt->width : 1);
}
