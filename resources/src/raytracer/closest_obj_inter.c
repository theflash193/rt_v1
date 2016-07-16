/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   closest_obj_inter.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/06 09:16:42 by grass-kw          #+#    #+#             */
/*   Updated: 2016/07/16 06:05:47 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_v1.h"

t_obj	*closest_obj_inter(t_env *e, t_vector3d start, t_vector3d ray)
{
	t_obj	*intersection;
	double	distance;
	double	result;
	t_list	*cursor;

	cursor = e->list_obj;
	distance = 200000;
	intersection = NULL;
	while (cursor)
	{
		result = inter(cursor->content, &start, &ray);
		if (result < distance && result > ZERO)
		{
			distance = result;
			e->k = distance;
			intersection = cursor->content;
		}
		cursor = cursor->next;
	}
	return (intersection);
}
