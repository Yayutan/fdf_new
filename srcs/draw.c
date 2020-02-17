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

static void			draw_line(void *image, t_2dpt p1, t_2dpt p2, int[3] info)
{

}

int					draw_image(t_mlx *mlx)
{
	int				r;
	int				c;
	int				info[3];

	if (mlx->image)
		mlx_destroy_image(mlx->mlx, mlx->image);
	if (!(mlx->image = mlx_new_image(mlx->mlx, mlx->win_x, mlx->win_y)))
		return (0);
	mlx_get_data_addr(mlx->image, info, info + 1, info + 2);
	r = 0;
	while (r < mlx->n_r)
	{
		c = 0;
		while (c < mlx->n_c - 1)
		{
			draw_line(mlx->image, mlx->tw_dpt[r][c], mlx->tw_dpt[r][c + 1], info);
			if (r + 1 < mlx->n_r)
				draw_line(mlx->image, mlx->tw_dpt[r][c], mlx->tw_dpt[r + 1][c], info);
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
	if (!(draw_image(mlx)))
		return (0);	
	return (1);	
}