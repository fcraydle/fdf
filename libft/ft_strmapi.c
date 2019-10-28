/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcraydle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 16:27:38 by fcraydle          #+#    #+#             */
/*   Updated: 2019/04/23 17:20:51 by fcraydle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*new_s;
	size_t	i;

	if (!s || !f)
		return (NULL);
	new_s = ft_strdup(s);
	if (new_s == NULL)
		return (NULL);
	i = 0;
	while (i < ft_strlen(s))
	{
		new_s[i] = f(i, s[i]);
		i++;
	}
	return (new_s);
}
