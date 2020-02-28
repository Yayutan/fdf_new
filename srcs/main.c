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

static void			clean_struct(t_mlx *mlx)
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

static t_mlx		init_fdf(void)
{
	t_mlx			to_ret;

	to_ret.win = NULL;
	to_ret.mlx = NULL;
	to_ret.image = NULL;
	to_ret.n_r = 0;
	to_ret.n_c = -1;
	to_ret.win_x = 750;
	to_ret.win_y = 600;
	to_ret.win_sc[0] = -1;
	to_ret.win_sc[1] = -1;
	to_ret.ang[0] = -M_PI / 12;
	to_ret.ang[1] = 0.0;
	to_ret.ang[2] = -M_PI / 12;
	to_ret.sht[0] = to_ret.win_x / 2;
	to_ret.sht[1] = to_ret.win_y / 2;
	to_ret.str[0] = 1;
	to_ret.str[1] = 1;
	to_ret.str[2] = 1;
	to_ret.th_dpt = NULL;
	to_ret.tw_dpt = NULL;
	to_ret.min_z = (double)INT_MAX;
	to_ret.max_z = (double)INT_MIN;	
	return (to_ret);
}

static void			reset_draw_param(t_mlx *mlx)
{
	mlx->ang[0] = -M_PI / 12;
	mlx->ang[1] = 0.0;
	mlx->ang[2] = -M_PI / 12;
	mlx->sht[0] = mlx->win_x / 2;
	mlx->sht[1] = mlx->win_y / 2;
	mlx->str[0] = 1;
	mlx->str[1] = 1;
	mlx->str[2] = 1;
}

static int			key_handler(int k, t_mlx *mlx)
{
	printf ("%d\n", k);
	if (k == 53)
		exit(0);
	if (k == 15)
		reset_draw_param(mlx);
	if (k == 0 || k == 1 || k == 2 || k == 6 || k == 7 || k == 8) // a;s;d;z;x;c
		rotate(mlx, k, -M_PI / 12); // M_PI
	// if (k == 123 || k == 124 || k == 125 || k == 126) // left;right;down;up
	// 	shift(mlx, k, 0.1);
	// if (k == 31 || k == 35 || k == 33 || k == 47 || k == 41 || k == 39) // o p [ l ; '
	// 	stretch(m, k, 0.1);
	// keys to change perspective?
	draw_image(mlx);
	return (k);
}

int					main(int ac, char **av)
{
	t_mlx			mlx;

	if (ac != 2)
		ft_err_exit("usage: ./fdf [file]");
	mlx = init_fdf();
	if(!read_verify(av[1], &mlx))
		ft_err_exit("Error");
	if (!init_pt(av[1], &mlx) || !init_win(&mlx))
	{
		clean_struct(&mlx);
		ft_err_exit("Failed to allocate pts and window");
	}
	if (!trans_coor(&mlx) || !draw_image(&mlx))
	{
		clean_struct(&mlx);
		ft_err_exit("Failed to put points to window");
	}
	mlx_key_hook(mlx.win, key_handler, &mlx);
	mlx_loop(mlx.mlx);
	return (0);
}
