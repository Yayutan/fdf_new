/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchuang <mchuang@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 18:58:30 by mchuang           #+#    #+#             */
/*   Updated: 2019/09/19 18:58:31 by mchuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		find_st_ed(char const *s, int *st, int *ed)
{
	*st = 0;
	*ed = ft_strlen(s) - 1;
	while (*st <= *ed && (s[*st] == ' ' || s[*st] == '\t' || s[*st] == '\n' ||
						s[*st] == '\v' || s[*st] == '\f' || s[*st] == '\r'))
		(*st)++;
	while (*ed >= 0 && (s[*ed] == ' ' || s[*ed] == '\t' || s[*ed] == '\n' ||
					s[*ed] == '\v' || s[*ed] == '\f' || s[*ed] == '\r'))
		(*ed)--;
}

char			*ft_strtrim(char const *s)
{
	int		st;
	int		ed;
	int		cur;
	char	*to_ret;

	if (!s)
		return (NULL);
	find_st_ed(s, &st, &ed);
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
