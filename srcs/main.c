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



static int			key_handler(int k, t_mlx *mlx)
{
	printf ("%d\n", k);
	if (k == 53)
		exit(0); // transform only in my best mode
	if (k == 15)
		reset_draw_param(&mlx->param, &mlx->orig);
	if (k == 0 || k == 1 || k == 2 || k == 6 || k == 7 || k == 8) // a;s;d;z;x;c
		rotate(&mlx->param, k, -M_PI / 12); // M_PI
	if (k == 123 || k == 124 || k == 125 || k == 126) // left;right;down;up
		shift(mlx, k, 0.1);
	if (k == 31 || k == 35 || k == 33 || k == 37 || k == 41 || k == 39) // o p [ l ; '
		stretch(&mlx->param, k, 0.1);
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
