/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ft_strsub.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcraydle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 12:52:47 by fcraydle          #+#    #+#             */
/*   Updated: 2019/04/23 17:18:06 by fcraydle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(const char *s, unsigned int start, size_t len)
{
	char	*cpy;
	size_t	i;
	size_t	j;

	if (s == 0)
		return (NULL);
	if ((cpy = (char *)malloc(sizeof(char) * (len + 1))) == 0)
		return (NULL);
	i = start;
	j = 0;
	while (i < start + len)
	{
		cpy[j] = s[i];
		++j;
		++i;
	}
	cpy[j] = 0;
	return (cpy);
}
