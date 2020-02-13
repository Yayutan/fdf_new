/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchuang <mchuang@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 15:11:25 by mchuang           #+#    #+#             */
/*   Updated: 2019/09/28 15:11:37 by mchuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	calc_digits(unsigned long long n, int b)
{
	int					digits;
	unsigned long long	cur;

	cur = n;
	digits = 1;
	while (cur >= (unsigned long long)b)
	{
		cur /= b;
		digits++;
	}
	return (digits);
}

char		*ft_ulltoa_base(unsigned long long n, int b)
{
	int						i;
	int						digits;
	unsigned long long		cur;
	char					*to_ret;
	char					*ref;

	ref = "0123456789abcdef";
	digits = calc_digits(n, b);
	to_ret = ft_strnew(digits);
	if (!to_ret)
		return (NULL);
	i = 0;
	cur = n;
	while (digits > i)
	{
		to_ret[digits - 1] = ref[cur % b];
		digits--;
		cur /= b;
	}
	return (to_ret);
}
