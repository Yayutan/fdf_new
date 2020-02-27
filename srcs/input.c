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

static int			valid_int(char *str)
{
	int				i;

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

static int			verify_line(char *line, int *cmp)
{
	char			**ele;
	int				n_col;

	if (!line)
		return (0);
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

static void			add_line(char *line, t_3dpt *arr, t_mlx *mlx, int row)
{
	int				a_i;
	int				s_i;

	a_i = 0;
	s_i = 0;
	while (line[s_i] && line[s_i] == ' ')
		s_i++;
	while (line[s_i] && a_i < mlx->n_c)
	{
		arr[a_i].x = a_i - ((double)(mlx->n_c - 1) / 2);
		arr[a_i].y = row - ((double)(mlx->n_r - 1) / 2);
		arr[a_i].z = (double)ft_atoi(line + s_i++);
		while (line[s_i] && line[s_i] == ' ')
			s_i++;
		a_i++;
	}
}

int					init_pt(char *filename, t_mlx *mlx)
{
	int				fd;
	int				r;
	char			*line;

	if ((fd = open(filename, O_RDONLY)) < 0)
		return (0);
	if (!(mlx->th_dpt = (t_3dpt**)ft_memalloc(mlx->n_r * sizeof(t_3dpt*))))
		return (0);
	r = 0;
	while (get_next_line(fd, &line) > 0)
	{
		mlx->th_dpt[r] = (t_3dpt*)ft_memalloc(mlx->n_c * sizeof(t_3dpt));
		add_line(line, mlx->th_dpt[r], mlx, -1 * r);
		r++;
	}
	/////////
	// for (int i = 0; i < mlx->n_r; i++)
	// {
	// 	for (int j = 0; j < mlx->n_c; j++)
	// 		printf("(%.2f, %.2f, %.2f) ", mlx->th_dpt[i][j].x, mlx->th_dpt[i][j].y, mlx->th_dpt[i][j].z);
	// 	printf("\n");
	// }
	////////
	close(fd);
	return (1);
}
