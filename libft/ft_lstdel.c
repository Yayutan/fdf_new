/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchuang <mchuang@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 12:09:10 by mchuang           #+#    #+#             */
/*   Updated: 2019/09/20 12:09:12 by mchuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *next;

	if (!alst || !*alst)
		return ;
	while (*alst != NULL)
	{
		next = (*alst)->next;
		(*del)(*alst, (*alst)->content_size);
		*alst = next;
	}
}
