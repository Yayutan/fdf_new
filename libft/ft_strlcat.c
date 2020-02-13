/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchuang <mchuang@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 21:14:28 by mchuang           #+#    #+#             */
/*   Updated: 2019/09/18 21:14:30 by mchuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	desired_size;
	size_t	len1;
	size_t	len2;

	len1 = ft_strlen(dst);
	len2 = ft_strlen(src);
	desired_size = len1 + len2;
	if (dstsize < len1 + 1)
		return (len2 + dstsize);
	if (len2 < dstsize - len1)
		ft_strcat(dst, src);
	else
	{
		ft_strncat(dst, src, dstsize - len1 - 1);
	}
	return (desired_size);
}
