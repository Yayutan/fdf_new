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

static void			draw_line(t_mlx *mlx, int *img, t_2dpt p1, t_2dpt p2)
{
	int				dx;
	int				dy;
	int				sx;
	int				sy;
	int				err;
	int				e2;

	// printf("(%d,%d)->(%d,%d)\n", p1.x, p1.y, p2.x, p2.y);
	dx = abs(p2.x - p1.x);
	dy = -1 * abs(p2.y - p1.y);
	sx = (p2.x > p1.x) ? 1 : -1;
	sy = (p2.y > p1.y) ? 1 : -1;
	err = dx + dy;
	while (1)
	{
		// printf("P:%d,%d\n", p1.x, p1.y);
		if (p1.x >= 0 && p1.x < mlx->win_x && p1.y >= 0 && p1.y < mlx->win_y)
			img[p1.x + p1.y * mlx->win_x] = 0xffffff;
		if (p1.x == p2.x && p1.y == p2.y)
			break ;
		e2 = 2 * err;
		if (e2 >= dy)
		{
			err += dy;
			p1.x += sx;
		}
		if (e2 <= dx)
		{
			err += dx;
			p1.y += sy;
		}
	}
}

int					draw_image(t_mlx *mlx)
{
	int				r;
	int				c;
	int				info[3]; // maybe don't need?
	int				*img; 

	if (mlx->image)
		mlx_destroy_image(mlx->mlx, mlx->image); // don't do this every time
	if (!(mlx->image = mlx_new_image(mlx->mlx, mlx->win_x, mlx->win_y)))
		return (0);
	img = (int*)mlx_get_data_addr(mlx->image, info, info + 1, info + 2);
	r = 0;
	while (r < mlx->n_r)
	{
		c = 0;
		while (c < mlx->n_c)
		{
			if (c + 1 < mlx->n_c)
				draw_line(mlx, img, mlx->tw_dpt[r][c], mlx->tw_dpt[r][c + 1]);
			if (r + 1 < mlx->n_r)
				draw_line(mlx, img, mlx->tw_dpt[r][c], mlx->tw_dpt[r + 1][c]);
			c++;
		}
		r++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->image, 0, 0);
	return (1);
}		

int					init_win(t_mlx *mlx)
{
	if (!(mlx->mlx = mlx_init()))
		return (0);
	if (!(mlx->win = mlx_new_window(mlx->mlx, mlx->win_x, mlx->win_y, "fdf")))
		return (0);
	// if (!(mlx->tw_dpt = (t_2dpt**)ft_memalloc(sizeof(t_2dpt) * mlx->n_r * mlx->n_c)))
		// return (0);
	// if (!(draw_image(mlx)))
	// 	return (0);	
	return (1);	
}