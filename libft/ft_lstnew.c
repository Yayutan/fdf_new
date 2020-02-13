/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchuang <mchuang@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 12:09:59 by mchuang           #+#    #+#             */
/*   Updated: 2019/09/20 12:09:59 by mchuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *to_ret;

	to_ret = (t_list*)malloc(sizeof(t_list));
	if (!to_ret)
		return (NULL);
	to_ret->content = malloc(sizeof(void*));
	if (!to_ret->content)
		return (NULL);
	if (!content)
		to_ret->content = NULL;
	else
		ft_memmove(to_ret->content, content, content_size);
	to_ret->content_size = (content) ? content_size : 0;
	to_ret->next = NULL;
	return (to_ret);
}
