/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrimc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchuang <mchuang@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 21:51:52 by mchuang           #+#    #+#             */
/*   Updated: 2019/10/21 21:53:27 by mchuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		find_st_ed(char const *s, int *st, int *ed, char c)
{
	*st = 0;
	*ed = ft_strlen(s) - 1;
	while (*st <= *ed && s[*st] == c)
		(*st)++;
	while (*ed >= 0 && s[*ed] == c)
		(*ed)--;
}

char			*ft_strtrimc(char const *s, char c)
{
	int		st;
	int		ed;
	int		cur;
	char	*to_ret;

	if (!s)
		return (NULL);
	find_st_ed(s, &st, &ed, c);
	if (st == (int)ft_strlen(s) || ed == -1)
		return (ft_strnew(0));
	to_ret = ft_strnew(ed - st + 1);
	if (!to_ret)
		return (NULL);
	cur = st;
	while (cur <= ed)
	{
		to_ret[cur - st] = s[cur];
		cur++;
	}
	return (to_ret);
}
