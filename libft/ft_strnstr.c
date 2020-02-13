/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchuang <mchuang@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 21:15:04 by mchuang           #+#    #+#             */
/*   Updated: 2019/09/18 21:15:05 by mchuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hk, const char *nd, size_t len)
{
	size_t	cnth;
	size_t	cntn;
	size_t	tmp;

	if (nd[0] == '\0')
		return ((char*)hk);
	cnth = 0;
	cntn = 0;
	while (cnth < len && hk[cnth] != '\0')
	{
		if (hk[cnth] == nd[cntn])
		{
			tmp = cnth;
			while (nd[cntn] != '\0' && hk[tmp] == nd[cntn] && tmp < len)
			{
				tmp++;
				cntn++;
			}
			if (nd[cntn] == '\0')
				return ((char*)(hk + cnth));
			cntn = 0;
		}
		cnth++;
	}
	return (NULL);
}
