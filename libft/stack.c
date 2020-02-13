/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchuang <mchuang@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 16:50:25 by mchuang           #+#    #+#             */
/*   Updated: 2019/11/19 16:50:27 by mchuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_stack				*st_init(void)
{
	t_stack	*to_ret;

	to_ret = ft_memalloc(sizeof(t_stack));
	if (!to_ret)
		return (NULL);
	to_ret->head = NULL;
	to_ret->size = 0;
	return (to_ret);
}

t_stack				*push(t_stack *st, int n)
{
	t_int_node	*p;

	p = st->head;
	while (p)
	{
		if (p->data == n)
			return (NULL);
		p = p->next;
	}
	if (!(p = ft_memalloc(sizeof(t_int_node))))
		return (NULL);
	p->data = n;
	p->next = NULL;
	p->red = 0;
	p->index = -1;
	p->group = -1;
	if (!(st->head))
		st->head = p;
	else
	{
		p->next = st->head;
		st->head = p;
	}
	(st->size)++;
	return (st);
}

int					pop(t_stack *st)
{
	int			to_ret;
	t_int_node	*hd;

	if (!st || !(st->head))
		return (-42);
	to_ret = st->head->data;
	hd = st->head;
	st->head = st->head->next;
	free(hd);
	(st->size)--;
	return (to_ret);
}

int					peak(t_stack *st)
{
	if (!st || !(st->head))
		return (-42);
	return (st->head->data);
}

void				free_stack(t_stack *st)
{
	t_int_node	*cur;
	t_int_node	*tmp;

	if (!st)
		return ;
	cur = st->head;
	while (cur)
	{
		tmp = cur;
		cur = cur->next;
		free(tmp);
	}
	free(st);
}
