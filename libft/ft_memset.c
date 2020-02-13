/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchuang <mchuang@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 20:45:22 by mchuang           #+#    #+#             */
/*   Updated: 2019/09/18 20:45:26 by mchuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			cur;
	unsigned char	*a;

	cur = 0;
	a = (unsigned char *)b;
	while (cur < len)
	{
		a[cur] = (unsigned char)c;
		cur++;
	}
	return (b);
}
