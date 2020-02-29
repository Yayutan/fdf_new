/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchuang <mchuang@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 21:47:34 by mchuang           #+#    #+#             */
/*   Updated: 2020/02/27 21:47:49 by mchuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void				rotate(t_param *p, int k, double ang) // pass in param gio ok?
{
	if (k == 0)
		p->ang[0] += ang;
	else if (k == 1)
		p->ang[1] += ang;
	else if (k == 2)
		p->ang[2] += ang;
	else if (k == 6)
		p->ang[0] -= ang;
	else if (k == 7)
		p->ang[1] -= ang;
	else if (k == 8)
		p->ang[2] -= ang;	
}

void				shift(t_mlx *mlx, int k, double sh)
{
	if (k == 123)
		mlx->param.sht[0] -= (int)(sh * mlx->win_x);
	else if (k == 124)
		mlx->param.sht[0] += (int)(sh * mlx->win_x);
	else if (k == 126)
		mlx->param.sht[1] -= (int)(sh * mlx->win_y);
	else if (k == 125)
		mlx->param.sht[1] += (int)(sh * mlx->win_y);
}

void				stretch(t_param *p, int k, double per)
{
	if (k == 31)
		p->str[0] *= (1 + per);
	else if (k == 37 && p->str[0] * (1 - per) > 0)
		p->str[0] *= (1 - per);
	else if (k == 35)
		p->str[1] *= (1 + per);
	else if (k == 41 && p->str[1] * (1 - per) > 0)
		p->str[1] *= (1 - per);
	else if (k == 33)
		p->str[2] *= (1 + per);
	else if (k == 39 && p->str[2] * (1 - per) > 0)
		p->str[2] *= (1 - per);
}