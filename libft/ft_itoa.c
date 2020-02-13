/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchuang <mchuang@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 18:56:23 by mchuang           #+#    #+#             */
/*   Updated: 2019/09/19 18:56:34 by mchuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	calc_digits(int n)
{
	size_t	digits;
	int		cur;

	cur = (n < 0) ? -1 * n : n;
	digits = (n < 0) ? 2 : 1;
	while (cur >= 10)
	{
		cur /= 10;
		digits++;
	}
	return (digits);
}

char		*ft_itoa(int n)
{
	size_t	i;
	size_t	digits;
	int		cur;
	char	*to_ret;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	digits = calc_digits(n);
	to_ret = ft_strnew(digits);
	if (!to_ret)
		return (NULL);
	i = (n < 0) ? 1 : 0;
	cur = (n < 0) ? -1 * n : n;
	if (n < 0)
		to_ret[0] = '-';
	while (digits > i)
	{
		to_ret[digits - 1] = (char)(cur % 10 + 48);
		digits--;
		cur /= 10;
	}
	return (to_ret);
}
