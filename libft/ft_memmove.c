/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchuang <mchuang@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 21:15:39 by mchuang           #+#    #+#             */
/*   Updated: 2019/09/18 21:15:40 by mchuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			cur;
	unsigned char	*d2;
	unsigned char	*s2;

	if (dst == NULL && src == NULL)
		return (NULL);
	cur = 0;
	d2 = (unsigned char*)dst;
	s2 = (unsigned char*)src;
	while (cur < len)
	{
		if (dst > src)
			d2[len - 1 - cur] = s2[len - 1 - cur];
		else
			d2[cur] = s2[cur];
		cur++;
	}
	return (dst);
}
