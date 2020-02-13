/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchuang <mchuang@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 22:41:24 by mchuang           #+#    #+#             */
/*   Updated: 2019/09/20 22:41:25 by mchuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelat(t_list **lst, int pos)
{
	t_list	*cur;
	t_list	*prev;

	if (!lst || !(*lst))
		return ;
	else if (pos == 0)
		*lst = (*lst)->next;
	else
	{
		prev = NULL;
		cur = *lst;
		while (cur)
		{
			if (pos == 0)
			{
				prev->next = cur->next;
				return ;
			}
			pos--;
			prev = cur;
			cur = cur->next;
		}
	}
}
