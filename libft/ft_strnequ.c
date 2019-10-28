/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcraydle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 16:53:31 by fcraydle          #+#    #+#             */
/*   Updated: 2019/04/23 17:28:59 by fcraydle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	if (s1 == NULL || s2 == NULL)
		return (0);
	if (n == 0)
		return (1);
	while (*s1 && *s2 && n - 1 > 0)
	{
		if (*s1 == *s2)
		{
			s1++;
			s2++;
			n--;
		}
		else
			return (0);
	}
	if (*s1 == *s2)
		return (1);
	return (0);
}
