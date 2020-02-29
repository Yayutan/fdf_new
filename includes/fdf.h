/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchuang <mchuang@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 09:14:25 by mchuang           #+#    #+#             */
/*   Updated: 2020/02/14 13:13:25 by mchuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <limits.h>

////
#include <stdio.h>
////

# include <math.h>
# include "libft.h"
# include "get_next_line.h"
# include "mlx.h"


typedef struct	s_3dpt
{
	double		x;
	double		y;
	double		z;
}				t_3dpt;

typedef struct	s_2dpt
{
	int			x;
	int			y;
}				t_2dpt;

typedef struct s_param
{
	double		ang[3];
	int			sht[2];
	double		str[3];
}				t_param;

typedef struct s_mlx
{
	void		*win;
	void		*mlx;
	void		*image;
	int			n_r;
	int			n_c;
	int			win_x;
	int			win_y;
	int			win_sc[2];
	double		min_z;
	double		max_z;
	t_param		orig;
	t_param		param;
	// int			mode; // for other projections
	t_3dpt		**th_dpt;
	t_2dpt		**tw_dpt;

}				t_mlx;

int				read_verify(char *filename, t_mlx *mlx);
int				init_pt(char *filename, t_mlx *mlx);
int				init_win(t_mlx *mlx);
int				trans_coor(t_mlx *mlx);
int				draw_image(t_mlx *mlx);
void			rotate(t_param *mlx, int k, double ang);
void			shift(t_mlx *mlx, int k, double sh);
void				stretch(t_param *p, int k, double per);
void			reset_draw_param(t_param *param, t_param *orig);
t_mlx			init_fdf(void);
void			clean_struct(t_mlx *mlx);

#endif
