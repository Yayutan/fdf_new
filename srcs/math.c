/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchuang <mchuang@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 20:01:43 by mchuang           #+#    #+#             */
/*   Updated: 2020/02/16 20:01:45 by mchuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void			transform_pixel(t_mlx *mlx, t_3dpt **thd, t_2dpt **twd)
{
	int				r;
	int				c;
	double			x_sc;
	double			y_sc;

	r = 0;
	while (r < mlx->n_r)
	{
		c = 0;
		while (c < mlx->n_c)
		{
			twd[r][c].x = thd[r][c].x;
			twd[r][c].y = mlx->win_y - (thd[r][c].y + thd[r][c].z);
			c++;
		}
		
}

static void			transform_th_d(t_mlx *mlx, t_2dpt **twd)
{
	t_3dpt			th_d_coor[mlx->n_r][mlx->n_c];
	int				r;
	int				c;
	double			or[3];

	r = 0;
	while (r < mlx->n_r)
	{
		c = 0;
		while (c < mlx->n_c)
		{
			or[0] = mlx->th_dpt[r][c].x;
			or[1] = mlx->th_dpt[r][c].y;
			or[2] = mlx->th_dpt[r][c].z;
			th_d_coor[r][c].x = mlx->str[0] * (or[0] * (cos(mlx->ang[1]) * cos(mlx->ang[2])) + or[1] * (-1 * cos(mlx->ang[1]) * sin(mlx->ang[2])) + or[2] * (-1 * sin(mlx->ang[1])));
			th_d_coor[r][c].y = mlx->str[1] * (or[0] * (cos(mlx->ang[0]) * sin(mlx->ang[2]) - cos(mlx->ang[2]) * sin(mlx->ang[0]) * sin(mlx->ang[1])) + or[1] * (cos(mlx->ang[0]) * cos(mlx->ang[2]) + sin(mlx->ang[0]) * sin(mlx->ang[1]) * sin(mlx->ang[2])) + or[2] * (-1 * cos(mlx->ang[1]) * sin(mlx->ang[0])));
			th_d_coor[r][c].z = mlx->str[2] * (or[0] * (cos(mlx->ang[0]) * cos(mlx->ang[2]) * sin(mlx->ang[1]) + sin(mlx->ang[0]) * sin(mlx->ang[2])) + or[1] * (cos(mlx->ang[2]) * sin(mlx->ang[0]) - cos(mlx->ang[0]) * sin(mlx->ang[1]) * sin(mlx->ang[2])) + or[2] * (cos(mlx->ang[0]) * cos(mlx->ang[1])));
			c++;
		}
		r++;
	}
	transform_pixel(mlx, th_d_coor, twd);	
}

int					trans_coor(t_mlx *mlx)
{

	t_2dpt			tw_d_coor[mlx->n_r][mlx->n_c];

	transform_th_d(mlx, tw_d_coor);
	ft_memcpy(mlx->tw_dpt, tw_d_coor, sizeof(tw_d_coor));
	return (1);
}
