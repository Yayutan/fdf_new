/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchuang <mchuang@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 18:57:52 by mchuang           #+#    #+#             */
/*   Updated: 2019/09/19 18:57:53 by mchuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int cur;

	if (s && f)
	{
		cur = 0;
		while (s[cur] != '\0')
		{
			(*f)(cur, s + cur);
			cur++;
		}
	}
}
