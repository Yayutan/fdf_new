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

static void			calibrate(t_mlx *mlx, t_2dpt min, t_2dpt max)
{
	int				r;
	int				c;
	t_2dpt			mid;

	mid = mlx->tw_dpt[mlx->n_r / 2][mlx->n_c / 2];
	if (mlx->win_sc < 0)
	{
		mlx->win_sc = 0.8 * (((mlx->win_x / (max.x - min.x)) < (mlx->win_y / (max.y - min.y))) ? (mlx->win_x / (max.x - min.x)) : (mlx->win_y / (max.y - min.y)));
		// mlx->param.sht[0] = (mlx->win_x / 2) - ((min.x + max.x) / 2 - mid.x) * mlx->win_sc + mid.x;
		// mlx->param.sht[1] = (mlx->win_y * 3 / 4) - (max.y - mid.y) * mlx->win_sc + mid.y;
	}
	// mid.x = mlx->win_x / 2;
	// mid.y = mlx->win_y / 2;
	r = 0;
	while (r < mlx->n_r)
	{
		c = 0;
		while (c < mlx->n_c)
		{
			mlx->tw_dpt[r][c].x = (mlx->tw_dpt[r][c].x - mid.x) * mlx->win_sc + mid.x + mlx->param.sht[0];
			mlx->tw_dpt[r][c].y = (mlx->tw_dpt[r][c].y - mid.y) * mlx->win_sc + mid.y + mlx->param.sht[1];
			printf("[%d][%d]:(%d,%d)\n ", r, c, mlx->tw_dpt[r][c].x, mlx->tw_dpt[r][c].y);
			c++;
		}
		r++;
	}	
}

static void			transform_pixel(t_mlx *mlx, t_3dpt **thd)
{
	int				r;
	int				c;
	t_2dpt			max;
	t_2dpt			min;
	t_2dpt			res;

	max.x = INT_MIN;
	max.y = INT_MIN;
	min.x = INT_MAX;
	min.y = INT_MAX;
	r = 0;
	while (r < mlx->n_r)
	{
		c = 0;
		while (c < mlx->n_c)
		{
			res = general_projection(thd[r][c]);
			mlx->tw_dpt[r][c].x = res.x;
			mlx->tw_dpt[r][c].y = res.y;
			if (mlx->tw_dpt[r][c].x < min.x)
				min.x = mlx->tw_dpt[r][c].x;
			if (mlx->tw_dpt[r][c].x > max.x)
				max.x = mlx->tw_dpt[r][c].x;
			if (mlx->tw_dpt[r][c].y < min.y)
				min.y = mlx->tw_dpt[r][c].y;
			if (mlx->tw_dpt[r][c].y > max.y)
				max.y = mlx->tw_dpt[r][c].y;
			// if (res.x < min.x)
			// 	min.x = res.x;
			// if (res.x > max.x)
			// 	max.x = res.x;
			// if (res.y < min.y)
			// 	min.y = res.y;
			// if (res.y > max.y)
			// 	max.y = res.y;
			printf("[%d][%d]:(%d,%d)\n ", r, c, mlx->tw_dpt[r][c].x, mlx->tw_dpt[r][c].y);
			c++;
		}
		r++;
	}
	calibrate(mlx, min, max);
}

static void			transform_th_d(t_mlx *mlx)
{ // err chk, free
	t_3dpt			**th_d_coor;
	int				r;
	int				c;
	double			or[3];
	t_3dpt			mid;

	th_d_coor = (t_3dpt**)ft_memalloc(sizeof(t_3dpt*) * mlx->n_r);
	r = 0;
	while (r < mlx->n_r)
	{
		th_d_coor[r] = (t_3dpt*)ft_memalloc(sizeof(t_3dpt) * mlx->n_c);
		r++;
	}
	mid = mlx->th_dpt[mlx->n_r / 2][mlx->n_c / 2];
	r = 0;
	while (r < mlx->n_r)
	{
		c = 0;
		while (c < mlx->n_c)
		{
			or[0] = mlx->th_dpt[r][c].x - mid.x;
			or[1] = mlx->th_dpt[r][c].y - mid.y;
			or[2] = 0;







			th_d_coor[r][c].x = mlx->param.str[0] * (or[0] * (cos(mlx->param.ang[1]) * cos(mlx->param.ang[2]))
				+ or[1] * (-1 * cos(mlx->param.ang[1]) * sin(mlx->param.ang[2])) + or[2] * (-1 * sin(mlx->param.ang[1])));
			th_d_coor[r][c].y = mlx->param.str[1] * (or[0] * (cos(mlx->param.ang[0]) * sin(mlx->param.ang[2])
				- cos(mlx->param.ang[2]) * sin(mlx->param.ang[0]) * sin(mlx->param.ang[1])) + or[1] * (cos(mlx->param.ang[0]) * cos(mlx->param.ang[2])
				+ sin(mlx->param.ang[0]) * sin(mlx->param.ang[1]) * sin(mlx->param.ang[2])) + or[2] * (-1 * cos(mlx->param.ang[1]) * sin(mlx->param.ang[0])));
			th_d_coor[r][c].z = mlx->param.str[2] * (or[0] * (cos(mlx->param.ang[0]) * cos(mlx->param.ang[2]) * sin(mlx->param.ang[1])
				+ sin(mlx->param.ang[0]) * sin(mlx->param.ang[2])) + or[1] * (cos(mlx->param.ang[2]) * sin(mlx->param.ang[0]) - cos(mlx->param.ang[0])
				* sin(mlx->param.ang[1]) * sin(mlx->param.ang[2])) + or[2] * (cos(mlx->param.ang[0]) * cos(mlx->param.ang[1])));
			printf("(%.0f,%.0f,%.0f)->(%.0f,%.0f,%.0f)\n", or[0], or[1], or[2], th_d_coor[r][c].x, th_d_coor[r][c].y, th_d_coor[r][c].z);
			c++;
		}
		r++;
	}
	transform_pixel(mlx, th_d_coor); // merge into loop on top? if i can calc scale before the loop
	// free(th_d_coor);
}

int					trans_coor(t_mlx *mlx) // needs error check
{
	int				r;

	if (!mlx->tw_dpt)
	{
		mlx->tw_dpt = (t_2dpt**)ft_memalloc(sizeof(t_2dpt*) * mlx->n_r);
		r = 0;
		while (r < mlx->n_r)
		{
			mlx->tw_dpt[r] = (t_2dpt*)ft_memalloc(sizeof(t_2dpt) * mlx->n_c);
			r++;
		}
	}
	transform_th_d(mlx);
	// for (int i = 0; i < mlx->n_r; i++)
	// {
	// 	for (int j = 0; j < mlx->n_c; j++)
	// 		printf("(%.0f,%.0f,%.0f)->(%d,%d)\n ", mlx->th_dpt[i][j].x, mlx->th_dpt[i][j].y, mlx->th_dpt[i][j].z, mlx->tw_dpt[i][j].x, mlx->tw_dpt[i][j].y);
	// }
	// ft_memcpy(mlx->tw_dpt, tw_d_coor, sizeof(tw_d_coor));
	return (1);
}
	