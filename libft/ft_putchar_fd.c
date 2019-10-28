/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcraydle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 16:10:08 by fcraydle          #+#    #+#             */
/*   Updated: 2019/04/26 16:17:55 by fcraydle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"
#include <unistd.h>

void	ft_putchar_fd(char c, int fd)
{
	unsigned char	oct1;
	unsigned char	oct2;

	if (c < 0)
	{
		oct1 = ((unsigned char)c >> 6) | 192;
		oct2 = ((unsigned char)c | 63) | 128;
		write(fd, &oct1, 1);
		write(fd, &oct2, 1);
	}
	else
		write(fd, &c, 1);
}
