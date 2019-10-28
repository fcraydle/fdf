/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcraydle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 19:17:07 by fcraydle          #+#    #+#             */
/*   Updated: 2019/04/25 15:09:19 by fcraydle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_words(char const *s, char d)
{
	size_t	words;
	size_t	i;

	i = 0;
	words = 0;
	if (s[i] && s[i] != d)
		words++;
	while (s[i])
	{
		if ((s[i] == d) && (s[i + 1] != d) && (s[i + 1] != 0))
			words++;
		i++;
	}
	return (words);
}

static int	ft_splitstr(char **str, const char *s, char d, size_t len)
{
	size_t	count;
	size_t	lens;
	size_t	i;

	count = 0;
	i = 0;
	while (count < len)
	{
		lens = 0;
		while (s[i] == d && s[i])
			i++;
		while (s[i] != d && s[i])
		{
			lens++;
			i++;
		}
		if ((str[count] = ft_strsub(&s[i - lens], 0, lens)) == NULL)
		{
			ft_free(str, count);
			return (0);
		}
		count++;
	}
	str[count] = 0;
	return (1);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**str;
	int		len;

	if (!s)
		return (NULL);
	len = ft_words(s, c);
	if ((str = ((char **)ft_memalloc(sizeof(char *) * len + 1))) == NULL)
		return (NULL);
	if (ft_splitstr(str, s, c, len))
		return (str);
	else
		return (NULL);
	return (str);
}
