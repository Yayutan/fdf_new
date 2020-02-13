/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchuang <mchuang@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 21:16:03 by mchuang           #+#    #+#             */
/*   Updated: 2019/09/18 21:16:04 by mchuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			cur;
	unsigned char	*tmp;

	cur = 0;
	tmp = (unsigned char*)s;
	while (cur < n)
	{
		if (tmp[cur] == (unsigned char)c)
			return (tmp + cur);
		cur++;
	}
	return (NULL);
}
