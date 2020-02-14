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

static int	verify(char *line, int *cmp)
{
	char	**ele;
	int		n_col;

	if (!line)
		return (-1);
	n_col = 0;
	ele = ft_strsplit(line);
	// check num elements and valid elements (go see ps)

	return (1);
}

int			read_verify(char *filename, t_mlx *mlx)
{
	int		fd;
	int		n_row;
	char	*line;

	if ((fd = open(filename, O_RDONLY) < 0))
		return (0);
	n_row = 0;
	while (get_next_line(fd, &line) > 0)
	{
		if (!verify(line, &(mlx->n_c)))
		// update also mlx's dimensions
		if (line)
			free(line);
		n_row++;
	}
	if (line)
		free(line);
	close(fd);
	return (1);
}

int			init_pt(char *filename, t_mlx *mlx)
{
	if ((fd = open(filename, O_RDONLY) < 0))
		return (0);
	// read
		// make new horizontal array
		// gnl
		// split and make points
	close(fd);
	return (1);
}