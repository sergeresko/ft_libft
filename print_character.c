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

int		ft_print_character(const t_fmt *f, char c)
{
	if (!f->left)
		ft_putnchar((f->zero ? '0' : ' '), f->width - 1);
	ft_putchar(c);
	if (f->left)
		ft_putnchar(' ', f->width - 1);
	return (ft_max(1, f->width));
}
