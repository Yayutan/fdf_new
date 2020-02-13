/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchuang <mchuang@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 15:10:55 by mchuang           #+#    #+#             */
/*   Updated: 2019/09/28 15:11:15 by mchuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	calc_digits(long long int n, int b)
{
	int					digits;
	long long int		cur;

	cur = (n < 0) ? -1 * n : n;
	digits = (n < 0) ? 2 : 1;
	while (cur >= (long long)b)
	{
		cur /= b;
		digits++;
	}
	return (digits);
}

char		*ft_lltoa_base(long long int n, int b)
{
	int					i;
	int					digits;
	long long int		cur;
	char				*to_ret;
	char				*ref;

	ref = "0123456789abcdef";
	if (n == LLONG_MIN)
		return (ft_strdup("-9223372036854775808"));
	digits = calc_digits(n, b);
	to_ret = ft_strnew(digits);
	if (!to_ret)
		return (NULL);
	i = (n < 0) ? 1 : 0;
	cur = (n < 0) ? -1 * n : n;
	if (n < 0)
		to_ret[0] = '-';
	while (digits > i)
	{
		to_ret[digits - 1] = ref[cur % b];
		digits--;
		cur /= b;
	}
	return (to_ret);
}
