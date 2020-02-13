/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchuang <mchuang@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 21:15:56 by mchuang           #+#    #+#             */
/*   Updated: 2019/09/18 21:15:57 by mchuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			cur;
	unsigned char	*s3;
	unsigned char	*s4;

	cur = 0;
	s3 = (unsigned char*)s1;
	s4 = (unsigned char*)s2;
	while (cur < n)
	{
		if (s3[cur] != s4[cur])
			return (s3[cur] - s4[cur]);
		cur++;
	}
	if (cur < n)
		return (s3[cur] - s4[cur]);
	else
		return (0);
}
