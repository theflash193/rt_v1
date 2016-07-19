/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/10 07:48:31 by grass-kw          #+#    #+#             */
/*   Updated: 2016/07/19 18:27:29 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_v1.h"

static void			initialise_env(t_env *e)
{
	e->k = ZERO;
	e->intersection = 0;
}

static t_vector3d	calcul_intersection(double distance, t_vector3d *start,
	t_vector3d *ray)
{
	t_vector3d	inter;

	inter.x = start->x + (distance * ray->x);
	inter.y = start->y + (distance * ray->y);
	inter.z = start->z + (distance * ray->z);
	return (inter);
}

static void			calcul_light_inter_ray(t_vector3d *inter, t_list *list_spot)
{
	t_list	*cursor;
	t_obj	*light;

	cursor = list_spot;
	while (cursor)
	{
		light = (t_obj *)cursor->content;
		light->l = sub_vector(*inter, light->origin);
		light->l = normalize(light->l);
		cursor = cursor->next;
	}
}

t_color				raytracer(t_env *e, t_vector3d start, t_vector3d ray)
{
	t_color		final_color;
	t_obj		*object;
	t_vector3d	inter;

	final_color = set_rgb(0, 0, 0);
	object = closest_obj_inter(e, start, ray);
	e->object_inter = object;
	if (object != NULL)
	{
		inter = calcul_intersection(e->k, &start, &ray);
		calcul_light_inter_ray(&inter, e->list_spot);
		if (shadow(e, inter, object) != 1)
			final_color = shade(e, object, &inter, ray);
		final_color = add_rgb(final_color, ambient_color(object));
		valid_rgb(&final_color);
	}
	initialise_env(e);
	return (final_color);
}
