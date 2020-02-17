/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchuang <mchuang@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 13:12:51 by mchuang           #+#    #+#             */
/*   Updated: 2020/02/14 13:12:53 by mchuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int			key_handler(int k)
{
	if (k == 53)
		exit(0);

	return (k);
}

int					init_win(t_mlx *mlx)
{
	if (!(mlx->mlx = mlx_init()))
		return (-1);
	if (!(mlx->win = mlx_new_window(mlx->mlx, mlx->win_x, mlx->win_y, "fdf")))
		return (-1);
	mlx_key_hook(mlx->win, key_handler, NULL);
	return (1);	
}