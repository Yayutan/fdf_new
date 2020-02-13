/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchuang <mchuang@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 18:58:01 by mchuang           #+#    #+#             */
/*   Updated: 2019/09/19 18:58:02 by mchuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*to_ret;
	size_t	cur;

	if (!s || !f)
		return (NULL);
	to_ret = ft_strnew(ft_strlen(s));
	if (!to_ret)
		return (NULL);
	cur = 0;
	while (s[cur] != '\0')
	{
		to_ret[cur] = (*f)(s[cur]);
		cur++;
	}
	return (to_ret);
}
