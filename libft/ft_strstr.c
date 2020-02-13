/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchuang <mchuang@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 21:15:16 by mchuang           #+#    #+#             */
/*   Updated: 2019/09/18 21:15:16 by mchuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	cnth;
	size_t	cntn;
	size_t	tmp;

	if (needle[0] == '\0')
		return ((char*)haystack);
	cnth = 0;
	cntn = 0;
	while (haystack[cnth] != '\0')
	{
		if (haystack[cnth] == needle[cntn])
		{
			tmp = cnth;
			while (needle[cntn] != '\0' && haystack[tmp] == needle[cntn])
			{
				tmp++;
				cntn++;
			}
			if (needle[cntn] == '\0')
				return ((char*)(haystack + cnth));
			cntn = 0;
		}
		cnth++;
	}
	return (NULL);
}
