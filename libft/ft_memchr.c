/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcraydle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 11:15:27 by fcraydle          #+#    #+#             */
/*   Updated: 2019/04/23 17:27:23 by fcraydle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *arr, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	d;

	d = (unsigned char)c;
	i = 0;
	if (!arr && n == 0)
		return (NULL);
	str = (unsigned char*)arr;
	while (str[i] != d && i < (n - 1))
		i++;
	if (str[i] == d && n != 0)
		return (str += i);
	return (NULL);
}
