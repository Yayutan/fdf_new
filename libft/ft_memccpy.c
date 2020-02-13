/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchuang <mchuang@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 21:16:43 by mchuang           #+#    #+#             */
/*   Updated: 2019/09/18 21:18:34 by mchuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *d, const void *s, int c, size_t n)
{
	size_t			cur;
	unsigned char	*d2;
	unsigned char	*s2;

	cur = 0;
	d2 = (unsigned char*)d;
	s2 = (unsigned char*)s;
	while (cur < n)
	{
		d2[cur] = s2[cur];
		if (s2[cur] == (unsigned char)c)
			return (d + cur + 1);
		cur++;
	}
	return (NULL);
}
