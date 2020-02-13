/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchuang <mchuang@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 18:58:06 by mchuang           #+#    #+#             */
/*   Updated: 2019/09/19 18:58:07 by mchuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*to_ret;
	unsigned int	cur;

	if (!s || !f)
		return (NULL);
	to_ret = ft_strnew(ft_strlen(s));
	if (!to_ret)
		return (NULL);
	cur = 0;
	while (s[cur] != '\0')
	{
		to_ret[cur] = (*f)(cur, s[cur]);
		cur++;
	}
	return (to_ret);
}
