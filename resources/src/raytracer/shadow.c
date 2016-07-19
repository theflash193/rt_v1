/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 23:54:29 by grass-kw          #+#    #+#             */
/*   Updated: 2016/07/19 17:39:15 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_v1.h"

static int	light_ray_obj_inter(t_env *e, t_vector3d start, t_vector3d ray, t_obj *object_inter)
{
	double		result;
	t_list		*cursor;
	t_obj		*object;

	cursor = e->list_obj;
	while (cursor)
	{
		object = cursor->content;
		if (object_inter != object)
		{
		result = inter(cursor->content, &start, &ray);
		// printf("type [%d]", object->type);
		if (result > ZERO && object->type != PLAN)
			return (1);
		}
		cursor = cursor->next;
	}
	return (0);
}

int			shadow(t_env *e, t_vector3d inter, t_obj *object)
{
	t_list	*cursor;
	t_obj	*light;

	cursor = e->list_spot;
	while (cursor)
	{
		light = (t_obj *)cursor->content;
		if (light_ray_obj_inter(e, inter, light->l, object))
			return (1);
		cursor = cursor->next;
	}
	return (0);
}
