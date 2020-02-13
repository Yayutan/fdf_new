/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_bk.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchuang <mchuang@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 22:41:00 by mchuang           #+#    #+#             */
/*   Updated: 2019/09/20 22:41:03 by mchuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_bk(t_list **lst, t_list *n)
{
	t_list	*cur;
	t_list	*prev;

	if (!lst)
		return ;
	else if (!(*lst))
		*lst = n;
	else
	{
		cur = *lst;
		prev = NULL;
		while (cur)
		{
			prev = cur;
			cur = cur->next;
		}
		prev->next = n;
	}
}
