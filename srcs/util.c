#include "fdf.h"

void				clean_struct(t_mlx *mlx)
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

void				reset_draw_param(t_param *param, t_param *orig)
{
	ft_memcpy(param->sht, orig->sht, sizeof(int) * 2);
	ft_memcpy(param->ang, orig->ang, sizeof(double) * 3);
	ft_memcpy(param->str, orig->str, sizeof(double) * 3);
}

t_mlx				init_fdf(void)
{
	t_mlx			to_ret;

	to_ret.win = NULL;
	to_ret.mlx = NULL;
	to_ret.image = NULL;
	to_ret.n_r = 0;
	to_ret.n_c = -1;
	to_ret.win_x = 750;
	to_ret.win_y = 600;
	to_ret.win_sc = -1;
	to_ret.orig.ang[0] = -M_PI / 12;
	to_ret.orig.ang[1] = 0.0;
	to_ret.orig.ang[2] = -M_PI / 12;
	to_ret.orig.sht[0] = to_ret.win_x / 2;
	to_ret.orig.sht[1] = to_ret.win_y / 2;
	to_ret.orig.str[0] = 1;
	to_ret.orig.str[1] = 1;
	to_ret.orig.str[2] = 1;
	to_ret.th_dpt = NULL;
	to_ret.tw_dpt = NULL;
	to_ret.min_z = (double)INT_MAX;
	to_ret.max_z = (double)INT_MIN;
	reset_draw_param(&to_ret.param, &to_ret.orig);
	return (to_ret);
}

