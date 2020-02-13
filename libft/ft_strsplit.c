/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchuang <mchuang@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 18:58:20 by mchuang           #+#    #+#             */
/*   Updated: 2019/09/19 18:58:21 by mchuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	figure_st_ed(char const *s, char c, int **st, int **ed)
{
	size_t		cur;
	int			num_wd;

	cur = 0;
	num_wd = 0;
	while (cur < ft_strlen(s))
	{
		if (s[cur] != c)
		{
			(*st)[num_wd] = cur;
			while (s[cur] != c && s[cur] != '\0')
				cur++;
			(*ed)[num_wd++] = cur;
			cur++;
		}
		else
			cur++;
	}
	(*st)[num_wd] = -1;
	(*ed)[num_wd] = -1;
	return (num_wd);
}

char		**ft_strsplit(char const *s, char c)
{
	int		*st;
	int		*ed;
	char	**to_ret;
	int		cur;

	if (!s)
		return (NULL);
	st = (int*)ft_memalloc((ft_strlen(s) / 2 + 2) * sizeof(int));
	ed = (int*)ft_memalloc((ft_strlen(s) / 2 + 2) * sizeof(int));
	if (!st || !ed)
		return (NULL);
	to_ret = (char**)malloc((figure_st_ed(s, c, &st, &ed) + 1) * sizeof(char*));
	if (!to_ret)
		return (NULL);
	cur = 0;
	while (st[cur] >= 0 && ed[cur] >= 0)
	{
		to_ret[cur] = ft_strsub(s, st[cur], ed[cur] - st[cur]);
		cur++;
	}
	to_ret[cur] = NULL;
	free(st);
	free(ed);
	return (to_ret);
}
