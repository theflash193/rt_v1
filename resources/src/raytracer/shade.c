/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shade.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/06 10:12:11 by grass-kw          #+#    #+#             */
/*   Updated: 2016/07/16 07:43:53 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_v1.h"

t_vector3d	calcul_normal(t_obj *object, t_vector3d *inter)
{
	t_vector3d	n;
	t_vector3d	tmp;
	double		angle;


	if (object->type == SPHERE)
		n = sub_vector(object->origin, *inter);
	if (object->type == PLAN)
		n = object->origin;
	if (object->type == CYLINDRE)
	{
		n = sub_vector(object->origin, *inter);
		n.z = 0;
		rotation(&n, object->angle);
	}
	if (object->type == CONE)
	{
		angle = pow(tan(object->size * M_PI / 180), 2);
		n = sub_vector(object->origin, *inter);
		n.z = n.z * -angle;
		rotation(&n, object->angle);
	}
	n = normalize(n);
	return (n);
}

t_color		shade(t_env *e, t_obj *object, t_vector3d *inter, t_vector3d ray)
{
	t_color		final_color;
	t_vector3d	n;
	t_obj		*light;
	int			i;
	t_list		*cursor;

	i = 0;
	cursor = e->list_spot;
	final_color = set_rgb(0, 0, 0);
	while (cursor)
	{
		i++;
		light = (t_obj *)cursor->content;
		n = calcul_normal(object, inter);
		final_color = add_rgb(final_color, diffuse_color(light, n, object));
		final_color = add_rgb(final_color,
			specular_color(light, n, object, ray));
		cursor = cursor->next;
	}
	if (i > 0)
		final_color = set_rgb(final_color.r / i,
			final_color.g / i, final_color.b / i);
	valid_rgb(&final_color);
	return (final_color);
}
