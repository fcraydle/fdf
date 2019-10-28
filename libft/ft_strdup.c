/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcraydle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 11:08:33 by fcraydle          #+#    #+#             */
/*   Updated: 2019/04/19 11:09:30 by fcraydle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	int		s;
	int		i;
	char	*mem;

	s = 0;
	i = 0;
	while (src[s] != '\0')
		s++;
	mem = (char*)malloc(sizeof(*mem) * (s + 1));
	if (mem == 0)
		return (NULL);
	while (i <= s)
	{
		mem[i] = src[i];
		i++;
	}
	return (mem);
}
