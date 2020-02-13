/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchuang <mchuang@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 20:44:15 by mchuang           #+#    #+#             */
/*   Updated: 2019/09/18 20:45:15 by mchuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	size_t	cur;
	int		to_ret;
	size_t	neg;

	cur = 0;
	to_ret = 0;
	neg = 0;
	while (str[cur] == ' ' || str[cur] == '\t' || str[cur] == '\n' ||
		str[cur] == '\v' || str[cur] == '\f' || str[cur] == '\r')
		cur++;
	if (str[cur] == '-')
	{
		cur++;
		neg = 1;
	}
	else if (str[cur] == '+')
		cur++;
	while (ft_isdigit(str[cur]))
	{
		to_ret *= 10;
		to_ret += str[cur++] - 48;
	}
	if (neg)
		to_ret *= -1;
	return (to_ret);
}
