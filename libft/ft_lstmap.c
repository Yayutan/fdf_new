/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchuang <mchuang@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 12:09:52 by mchuang           #+#    #+#             */
/*   Updated: 2019/09/20 12:09:53 by mchuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*to_ret;
	t_list	*cur;

	if (!lst)
		return (NULL);
	to_ret = (*f)(lst);
	cur = to_ret;
	lst = lst->next;
	while (lst)
	{
		cur->next = (*f)(lst);
		lst = lst->next;
		cur = cur->next;
	}
	return (to_ret);
}
