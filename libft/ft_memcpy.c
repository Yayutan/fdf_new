/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchuang <mchuang@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 21:15:48 by mchuang           #+#    #+#             */
/*   Updated: 2019/09/18 21:15:49 by mchuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			cur;
	unsigned char	*d2;
	unsigned char	*s2;

	if (dst == NULL && src == NULL)
		return (NULL);
	cur = 0;
	d2 = (unsigned char*)dst;
	s2 = (unsigned char*)src;
	while (cur < n)
	{
		d2[cur] = s2[cur];
		cur++;
	}
	return (dst);
}
