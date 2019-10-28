/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcraydle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 13:52:27 by fcraydle          #+#    #+#             */
/*   Updated: 2019/04/19 11:24:09 by fcraydle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*strnew;
	const unsigned char	*str;

	strnew = (unsigned char *)dst;
	str = (const unsigned char *)src;
	while (n > 0)
	{
		*strnew = *str;
		strnew++;
		str++;
		n--;
	}
	return (dst);
}
