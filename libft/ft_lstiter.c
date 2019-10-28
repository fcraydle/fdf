/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcraydle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 10:45:50 by fcraydle          #+#    #+#             */
/*   Updated: 2019/04/23 16:23:19 by fcraydle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list	*new;
	t_list	*next;

	if (lst && f)
	{
		new = lst;
		while (new->next)
		{
			next = new->next;
			f(new);
			new = next;
		}
		f(new);
	}
}
