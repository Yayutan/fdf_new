/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchuang <mchuang@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 10:16:44 by mchuang           #+#    #+#             */
/*   Updated: 2019/09/21 10:16:46 by mchuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		read_till_nl(int fd, char **residual)
{
	char		*nl_loc;
	char		*tmp;
	int			bytes_read;
	char		buf[BUFF_SIZE + 1];

	while ((bytes_read = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[bytes_read] = '\0';
		if (!(*residual))
			*residual = ft_strnew(0);
		nl_loc = ft_strchr(buf, 10);
		tmp = ft_strjoin(*residual, buf);
		free(*residual);
		*residual = tmp;
		if (nl_loc)
			break ;
	}
	return (bytes_read);
}

void	squeeze_residual(char **residual, char **line)
{
	char		*nl_loc;
	char		*tmp;

	nl_loc = ft_strchr(*residual, 10);
	if (nl_loc)
	{
		*line = ft_strsub(*residual, 0, nl_loc - *residual);
		tmp = ft_strdup(nl_loc + 1);
		free(*residual);
		if (!tmp[0])
		{
			*residual = NULL;
			free(tmp);
		}
		else
			*residual = tmp;
	}
	else
	{
		*line = ft_strdup(*residual);
		free(*residual);
		*residual = NULL;
	}
}

int		get_next_line(const int fd, char **line)
{
	static char	*residual[FD_LIMIT];
	char		*nl_loc;
	int			bytes_read;

	if (fd < 0 || !line)
		return (-1);
	nl_loc = NULL;
	if ((bytes_read = read_till_nl(fd, residual + fd)) < 0)
		return (-1);
	if (residual[fd] || bytes_read)
	{
		squeeze_residual(residual + fd, line);
		return (1);
	}
	return (0);
}
