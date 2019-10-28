/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcraydle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 15:00:42 by fcraydle          #+#    #+#             */
/*   Updated: 2019/04/23 17:17:09 by fcraydle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	size_t		d;
	size_t		s;
	size_t		i;

	d = ft_strlen(dest);
	s = ft_strlen((char*)src);
	i = 0;
	while (src[i] != '\0' && n != 0)
	{
		dest[d] = src[i];
		n--;
		i++;
		d++;
	}
	dest[d] = '\0';
	return (dest);
}
