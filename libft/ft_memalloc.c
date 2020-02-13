/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchuang <mchuang@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 18:51:46 by mchuang           #+#    #+#             */
/*   Updated: 2019/09/19 18:52:02 by mchuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *to_ret;

	to_ret = malloc(size);
	if (!to_ret)
		return (NULL);
	ft_bzero(to_ret, size);
	return (to_ret);
}
