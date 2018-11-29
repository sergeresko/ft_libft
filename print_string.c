/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 13:32:45 by syeresko          #+#    #+#             */
/*   Updated: 2018/11/23 16:31:44 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

#include <unistd.h>		// for write

int		ft_print_string(const t_fmt *f, const char *str)
{
	const char	null_msg[] = "(null)";
	int			n_characters;

	if (!str)
		str = null_msg;
	n_characters = ft_strlen(str);
	if (f->prec != PF_PREC_NONE && f->prec < n_characters)
		n_characters = f->prec;
	if (!f->left)
		ft_putnchar((f->zero) ? '0' : ' ', f->width - n_characters);
	write(1, str, n_characters);	// here write is used
	if (f->left)
		ft_putnchar(' ', f->width - n_characters);
	return (ft_max(f->width, n_characters));
}
