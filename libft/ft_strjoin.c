/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchuang <mchuang@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 18:57:56 by mchuang           #+#    #+#             */
/*   Updated: 2019/09/19 18:57:57 by mchuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	size_t	cur;
	char	*to_ret;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	to_ret = ft_strnew(len1 + len2 + 1);
	if (!to_ret)
		return (NULL);
	cur = 0;
	while (cur < len1)
	{
		to_ret[cur] = s1[cur];
		cur++;
	}
	while (cur < len1 + len2)
	{
		to_ret[cur] = s2[cur - len1];
		cur++;
	}
	to_ret[len1 + len2] = '\0';
	return (to_ret);
}
