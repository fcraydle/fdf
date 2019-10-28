/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcraydle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 14:46:43 by fcraydle          #+#    #+#             */
/*   Updated: 2019/04/19 10:48:05 by fcraydle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		val;
	char	*new;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	val = ft_strlen(s1) + ft_strlen(s2);
	new = (char*)malloc(val + 1);
	if (new == 0)
		return (NULL);
	while (*s1)
	{
		*new = *s1;
		new++;
		s1++;
	}
	while (*s2)
	{
		*new = *s2;
		new++;
		s2++;
	}
	*new = '\0';
	return (new - val);
}
