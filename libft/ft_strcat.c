/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchuang <mchuang@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 20:45:35 by mchuang           #+#    #+#             */
/*   Updated: 2019/09/18 20:45:37 by mchuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	size_t	len1;
	size_t	len2;
	size_t	cur;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	cur = 0;
	while (cur < len2)
	{
		s1[len1 + cur] = s2[cur];
		cur++;
	}
	s1[len1 + cur] = '\0';
	return (s1);
}
