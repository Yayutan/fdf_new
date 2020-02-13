/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchuang <mchuang@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 18:57:15 by mchuang           #+#    #+#             */
/*   Updated: 2019/09/19 18:57:17 by mchuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int	pow10;
	int	cur;

	cur = n;
	if (n == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	else
	{
		if (cur < 0)
		{
			ft_putchar_fd('-', fd);
			cur *= -1;
		}
		pow10 = 1;
		while (cur / pow10 >= 10)
			pow10 *= 10;
		while (pow10 > 0)
		{
			ft_putchar_fd((char)(cur / pow10 + 48), fd);
			cur = cur % pow10;
			pow10 /= 10;
		}
	}
}
