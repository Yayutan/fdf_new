/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchuang <mchuang@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 21:15:10 by mchuang           #+#    #+#             */
/*   Updated: 2019/09/18 21:15:11 by mchuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int cur;

	cur = ft_strlen(s);
	while (cur >= 0)
	{
		if (s[cur] == (char)c)
			return ((char*)(s + cur));
		cur--;
	}
	return (NULL);
}
