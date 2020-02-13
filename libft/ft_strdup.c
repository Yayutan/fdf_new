/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchuang <mchuang@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 21:14:16 by mchuang           #+#    #+#             */
/*   Updated: 2019/09/18 21:14:18 by mchuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*toret;
	size_t	cur;
	size_t	max;

	max = ft_strlen(s1);
	toret = ft_strnew(max);
	if (!toret)
		return (NULL);
	cur = 0;
	while (cur < max)
	{
		toret[cur] = s1[cur];
		cur++;
	}
	return (toret);
}
