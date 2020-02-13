/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchuang <mchuang@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 22:41:51 by mchuang           #+#    #+#             */
/*   Updated: 2019/09/20 22:41:53 by mchuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstat(t_list *lst, int pos)
{
	t_list	*cur;

	if (!lst)
		return (NULL);
	else if (pos == 0)
		return (lst);
	else
	{
		cur = lst;
		while (cur)
		{
			if (pos == 0)
				return (cur);
			pos--;
			cur = cur->next;
		}
		return (NULL);
	}
}
