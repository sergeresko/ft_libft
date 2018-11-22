/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 18:59:57 by syeresko          #+#    #+#             */
/*   Updated: 2018/11/22 19:07:04 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnchar(char c, int times)
{
	char	buf[16];

	ft_memset(buf, c, sizeof(buf));
	while (times > sizeof(buf))
	{
		write(STDOUT_FILENO, buf, sizeof(buf));
		times -= sizeof(buf);
	}
	if (times > 0)
		write(STDOUT_FILENO, buf, times);
}
