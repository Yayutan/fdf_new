/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchuang <mchuang@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 13:12:57 by mchuang           #+#    #+#             */
/*   Updated: 2020/02/14 13:12:58 by mchuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
# include <stdio.h>

static int				valid_int(char *str)
{
	int					*to_ret;
	long long int		content;
	int					i;

	if (!str || !*str)
		return (0);
	i = (ft_strchr("+-", str[0])) ? 1 : 0;
	if (i == 1 && !(str[i]))
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

static int				verify_line(char *line, int *cmp)
{
	char				**ele;
	int					n_col;

	if (!line)
		return (-1);
	n_col = 0;
	ele = ft_strsplit(line, ' ');
	while (ele[n_col])
	{
		if (!valid_int(ele[n_col]))
			return (0);
		n_col++;
	}
	if (*cmp == -1)
		*cmp = n_col;
	else if (*cmp != n_col)
		return (0);
	return (1);
}

int						read_verify(char *filename, t_mlx *mlx)
{
	int					fd;
	char				*line;

	if ((fd = open(filename, O_RDONLY)) < 0)
		return (0);
	mlx->n_r = 0;
	while (get_next_line(fd, &line) > 0)
	{
		if (!verify_line(line, &(mlx->n_c)))
		{
			if (line)
				free(line);
			return (0);
		}
		if (line)
			free(line);
		mlx->n_r++;
	}
	close(fd);
	return (1);
}

static void				add_line(char *line, t_2dpt *arr, int n_c)
{

}

int						init_pt(char *filename, t_mlx *mlx)
{
	int					fd;
	int					r;
	char				*line;

	if ((fd = open(filename, O_RDONLY) < 0))
		return (0);
	mlx->tw_dpt = (t_2dpt**)ft_memalloc(mlx->n_r * sizeof(t_2dpt*));
	r = 0;
	while (get_next_line(fd, &line) > 0)
	{
		mlx->tw_dpt[r] = (t_2dpt*)ft_memalloc(mlx->n_c * sizeof(t_2dpt));
		add_line(line, mlx->tw_dpt[r], mlx->n_c);
		r++;
	}
	close(fd);
	return (1);
}