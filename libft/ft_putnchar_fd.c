/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnchar_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 19:04:20 by syeresko          #+#    #+#             */
/*   Updated: 2018/11/22 19:08:47 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnchar_fd(char c, int times, int fd)
{
	char	buf[16];

	ft_memset(buf, c, sizeof(buf));
	while (times > sizeof(buf))
	{
		write(fd, buf, sizeof(buf));
		times -= sizeof(buf);
	}
	if (times > 0)
		write(fd, buf, times);
}
