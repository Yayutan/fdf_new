/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchuang <mchuang@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 16:50:30 by mchuang           #+#    #+#             */
/*   Updated: 2019/11/19 16:50:34 by mchuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"

t_queue				*q_init(void)
{
	t_queue	*to_ret;

	to_ret = ft_memalloc(sizeof(t_queue));
	if (!to_ret)
		ft_err_exit("Failed to alllocate queue");
	to_ret->head = NULL;
	to_ret->tail = NULL;
	to_ret->size = 0;
	return (to_ret);
}

t_queue				*enqueue(t_queue *q, char *str)
{
	t_str_node	*p;

	p = ft_memalloc(sizeof(t_str_node));
	if (!p)
		return (NULL);
	p->data = ft_strdup(str);
	p->next = NULL;
	if (!(q->head))
	{
		q->head = p;
		q->tail = p;
	}
	else
	{
		q->tail->next = p;
		q->tail = p;
	}
	(q->size)++;
	return (q);
}

char				*dequeue(t_queue *q)
{
	char		*to_ret;
	t_str_node	*hd;

	if (!q || !(q->head))
		return ("-42");
	hd = q->head;
	to_ret = NULL;
	if (q->size == 1)
	{
		q->head = NULL;
		q->tail = NULL;
	}
	else
		q->head = q->head->next;
	if (hd->data)
	{
		to_ret = ft_strdup(hd->data);
		free(hd->data);
	}
	free(hd);
	(q->size)--;
	return (to_ret);
}

char				*front(t_queue *q)
{
	if (!q || !(q->head))
		return ("-42");
	return (q->head->data);
}

void				free_queue(t_queue *q)
{
	t_str_node	*cur;
	t_str_node	*tmp;

	if (!q)
		return ;
	cur = q->head;
	while (cur)
	{
		tmp = cur;
		cur = cur->next;
		if (tmp->data)
			free(tmp->data);
		free(tmp);
	}
	free(q);
}
