/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchuang <mchuang@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 13:13:02 by mchuang           #+#    #+#             */
/*   Updated: 2020/02/14 13:13:04 by mchuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		clean_struct(t_mlx *mlx)
{
	if (mlx->win)
		free(mlx->win);
	if (mlx->mlx)
		free(mlx->mlx);
	if (mlx->image)
		free(mlx->image);
	if (mlx->th_dpt)
		free(mlx->th_dpt);
	if (mlx->tw_dpt)
		free(mlx->tw_dpt);
}

static t_mlx	init_mlx(void)
{
	t_mlx		to_ret;

	to_ret.win = NULL;
	to_ret.mlx = NULL;
	to_ret.image = NULL;
	to_ret.n_r = 0;
	to_ret.n_c = -1;
	to_ret.win_x = 750;
	to_ret.win_y = 600;
	to_ret.x_ang = 0.0;
	to_ret.y_ang = 0.0;
	to_ret.z_ang = 0.0;
	to_ret.x_sh = 0;
	to_ret.y_sh = 0;
	to_ret.z_sh = 0;
	to_ret.th_dpt = NULL;
	to_ret.tw_dpt = NULL;
	return (to_ret);
}

int				main(int ac, char **av)
{
	t_mlx		mlx;

	if (ac != 2)
		ft_err_exit("usage: ./fdf [file]");
	mlx = init_mlx();
	if(!read_verify(av[1], &mlx))
		ft_err_exit("Error");
	if (!init_pt(av[1], &mlx))
	{
		clean_struct(&mlx);
		ft_err_exit("Failed to allocate pts and window");
	}
	// setup win var (err chk??)
	// form initial image and draw
	// set loop hook and loop

	return (0);
}