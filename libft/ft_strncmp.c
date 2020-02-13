/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchuang <mchuang@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 21:14:51 by mchuang           #+#    #+#             */
/*   Updated: 2019/09/18 21:14:52 by mchuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			cur;
	unsigned char	*s3;
	unsigned char	*s4;

	s3 = (unsigned char*)s1;
	s4 = (unsigned char*)s2;
	if (n == 0)
		return (0);
	cur = 0;
	while (cur < n && s3[cur] != '\0' && s4[cur] != '\0')
	{
		if (s3[cur] != s4[cur])
			return (s3[cur] - s4[cur]);
		cur++;
	}
	if (cur == n)
		return (0);
	return (s3[cur] - s4[cur]);
}
