/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchuang <mchuang@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 21:47:34 by mchuang           #+#    #+#             */
/*   Updated: 2020/02/27 21:47:49 by mchuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void				rotate(t_mlx *mlx, int k, double ang)
{
	if (k == 0)
		mlx->ang[0] += ang;
	else if (k == 1)
		mlx->ang[1] += ang;
	else if (k == 2)
		mlx->ang[2] += ang;
	else if (k == 6)
		mlx->ang[0] -= ang;
	else if (k == 7)
		mlx->ang[1] -= ang;
	else if (k == 8)
		mlx->ang[2] -= ang;	
}

// void				shift(t_mlx *mlx, int k, double per)
// {
	
// }

// void				stretch(t_mlx *mlx, int k, double per)
// {
	
// }