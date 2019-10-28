/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcraydle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 17:30:43 by fcraydle          #+#    #+#             */
/*   Updated: 2019/04/19 12:11:07 by fcraydle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char *a;
	unsigned char l;

	a = (unsigned char*)b;
	l = (unsigned char)c;
	while (len > 0)
	{
		*a = l;
		a++;
		len--;
	}
	return (b);
}
