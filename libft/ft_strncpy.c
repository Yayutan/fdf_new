/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchuang <mchuang@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 21:14:58 by mchuang           #+#    #+#             */
/*   Updated: 2019/09/18 21:14:59 by mchuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	cur;
	size_t	max;

	cur = 0;
	max = ft_strlen(src);
	while (cur < len)
	{
		if (cur < max)
			dst[cur] = src[cur];
		else
			dst[cur] = '\0';
		cur++;
	}
	return (dst);
}
