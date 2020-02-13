/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchuang <mchuang@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 21:14:43 by mchuang           #+#    #+#             */
/*   Updated: 2019/09/18 21:14:45 by mchuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	len1;
	size_t	len2;
	size_t	fin;
	size_t	cur;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	fin = (len2 < n ? len2 : n);
	cur = 0;
	while (cur < fin)
	{
		s1[len1 + cur] = s2[cur];
		cur++;
	}
	s1[len1 + cur] = '\0';
	return (s1);
}
