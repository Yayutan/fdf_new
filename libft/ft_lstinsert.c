/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstinsert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchuang <mchuang@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 22:41:11 by mchuang           #+#    #+#             */
/*   Updated: 2019/09/20 22:41:13 by mchuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstinsert(t_list **lst, t_list *item, int pos)
{
	t_list	*cur;
	t_list	*prev;

	if (!lst)
		return ;
	else if (!(*lst) || pos == 0)
		ft_lstadd(lst, item);
	else
	{
		prev = NULL;
		cur = *lst;
		while (cur && pos >= 0)
		{
			if (pos == 0)
			{
				prev->next = item;
				item->next = cur;
			}
			pos--;
			prev = cur;
			cur = cur->next;
		}
		prev->next = item;
	}
}
