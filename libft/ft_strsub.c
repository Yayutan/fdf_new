/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchuang <mchuang@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 18:58:26 by mchuang           #+#    #+#             */
/*   Updated: 2019/09/19 18:58:27 by mchuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*to_ret;
	size_t	cur;

	if (!s)
		return (NULL);
	to_ret = ft_strnew(len);
	if (!to_ret)
		return (NULL);
	cur = 0;
	while (cur < len)
	{
		to_ret[cur] = s[start + cur];
		cur++;
	}
	return (to_ret);
}
