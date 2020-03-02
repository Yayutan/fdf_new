/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchuang <mchuang@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 10:39:36 by mchuang           #+#    #+#             */
/*   Updated: 2020/02/29 10:39:38 by mchuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_2dpt		general_projection(t_3dpt thd)
{
	t_2dpt			res;

	res.x = (int)(thd.x); // / z?
	res.y = ((int)thd.y - (int)thd.z); // might cause problem in terms of angles
	return (res);
}