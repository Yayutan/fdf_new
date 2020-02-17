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
# include "libft.h"
# include "get_next_line.h"
# include "mlx.h"


typedef struct	s_3dpt
{
	double		x;
	double		y;
	int			z;
}				t_3dpt;

typedef struct	s_2dpt
{
	int			px;
	int			py;
}				t_2dpt;

typedef struct s_mlx
{
	void		*win;
	void		*mlx;
	void		*image;
	int			n_r;
	int			n_c;
	int			win_x;
	int			win_y;
	int			scale;
	double		x_ang;
	double		y_ang;
	double		z_ang;
	int			x_sh;
	int			y_sh;
	int			z_sh;
	t_3dpt		**th_dpt;
	t_2dpt		**tw_dpt;

}				t_mlx;

int			read_verify(char *filename, t_mlx *mlx);
int			init_pt(char *filename, t_mlx *mlx);
int			init_win(t_mlx *mlx);
int			trans_coor(t_mlx *mlx);
int			draw_image(t_mlx *mlx);


#endif
