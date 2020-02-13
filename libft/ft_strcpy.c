/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchuang <mchuang@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 21:14:07 by mchuang           #+#    #+#             */
/*   Updated: 2019/09/18 21:14:08 by mchuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dst, const char *src)
{
	size_t	cur;
	size_t	max;

	cur = 0;
	max = ft_strlen(src) + 1;
	while (cur < max)
	{
		dst[cur] = src[cur];
		cur++;
	}
	return (dst);
}
