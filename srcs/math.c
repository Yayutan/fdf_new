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

static t_2dpt		parallel_proj(t_3dpt thd, int win_x, int win_y) // confirm matrix
{
	t_2dpt			res;

	res.x = win_x / 2 + (int)(thd.x);
	res.y = win_y / 2 + (int)(-thd.y - thd.z);
	return (res);
}

static void			transform_pixel(t_mlx *mlx, t_3dpt **thd)
{
	int				r;
	int				c;
	t_2dpt			res;

	r = 0;
	while (r < mlx->n_r)
	{
		c = 0;
		while (c < mlx->n_c)
		{
			res = parallel_proj(thd[r][c], mlx->win_x, mlx->win_y);// change to function pointer
			mlx->tw_dpt[r][c].x = res.x;
			mlx->tw_dpt[r][c].y = res.y;
			printf("(%.0f,%.0f,%.0f)->(%d,%d)\n ", thd[r][c].x, thd[r][c].y, thd[r][c].z, res.x, res.y);
			// update max, min if scale not set
			c++;
		}
		// calc scale if not set
		r++;
	}
}

static void			transform_th_d(t_mlx *mlx)
{ // err chk, free
	t_3dpt			**th_d_coor;
	int				r;
	int				c;
	double			or[3];

	th_d_coor = (t_3dpt**)ft_memalloc(sizeof(t_3dpt*) * mlx->n_r);
	r = 0;
	while (r < mlx->n_r)
	{
		th_d_coor[r] = (t_3dpt*)ft_memalloc(sizeof(t_3dpt) * mlx->n_c);
		r++;
	}
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
