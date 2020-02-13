/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stradd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchuang <mchuang@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 12:55:11 by mchuang           #+#    #+#             */
/*   Updated: 2019/10/02 12:55:43 by mchuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_stradd(char *s, char t, int m, int n)
{
	int		c;
	char	*tmp;

	if (n <= 0)
		return (ft_strdup(s));
	tmp = ft_strnew(ft_strlen(s) + n);
	if (m == -1)
	{
		ft_strncpy(tmp + n, s, ft_strlen(s));
		c = 0;
		while (c < n)
			tmp[c++] = t;
	}
	else if (m == 1)
	{
		ft_strncpy(tmp, s, ft_strlen(s));
		c = 0;
		while (c < n)
		{
			tmp[c + ft_strlen(s)] = t;
			c++;
		}
	}
	return (tmp);
}
