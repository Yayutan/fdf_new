/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchuang <mchuang@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 20:45:42 by mchuang           #+#    #+#             */
/*   Updated: 2019/09/18 20:45:47 by mchuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	len;
	size_t	cur;

	cur = 0;
	len = ft_strlen(s);
	while (cur <= len)
	{
		if (s[cur] == (char)c)
			return ((char*)(s + cur));
		cur++;
	}
	return (NULL);
}
