/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchuang <mchuang@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 18:57:10 by mchuang           #+#    #+#             */
/*   Updated: 2019/09/19 18:57:11 by mchuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	int	pow10;
	int	cur;

	cur = n;
	if (n == -2147483648)
		ft_putstr("-2147483648");
	else
	{
		if (cur < 0)
		{
			ft_putchar('-');
			cur *= -1;
		}
		pow10 = 1;
		while (cur / pow10 >= 10)
			pow10 *= 10;
		while (pow10 > 0)
		{
			ft_putchar((char)(cur / pow10 + 48));
			cur = cur % pow10;
			pow10 /= 10;
		}
	}
}
