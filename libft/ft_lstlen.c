/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchuang <mchuang@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 22:41:39 by mchuang           #+#    #+#             */
/*   Updated: 2019/09/20 22:41:40 by mchuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_lstlen(t_list *lst)
{
	size_t	size;
	t_list	*cur;

	if (!lst)
		return (0);
	cur = lst;
	size = 0;
	while (cur)
	{
		size++;
		cur = cur->next;
	}
	return (size);
}
