/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diffuse_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/27 15:09:58 by grass-kw          #+#    #+#             */
/*   Updated: 2016/07/20 10:32:59 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_v1.h"

double		diffuse_light(t_vector3d a, t_vector3d b)
{
	return (dot_product(a, b) /
		(sqrt((pow(a.x, 2) + pow(a.y, 2) + pow(a.z, 2))) *
		sqrt((pow(b.x, 2) + pow(b.y, 2) + pow(b.z, 2)))));
}

double		bright(double color, double angle, t_obj *object,
	double light_color)
{
	double new_color;

	new_color = color * angle * object->material.kd;
	return (new_color + object->material.shine * light_color * angle);
}

t_color		diffuse_color(t_obj *light, t_vector3d n, t_obj *object)
{
	t_color	color;
	double	angle;

	angle = diffuse_light(n, light->l);
	color = set_rgb(0, 0, 0);
	if (angle >= 0)
	{
		color.r = bright(object->color.r, angle, object, light->color.r);
		color.g = bright(object->color.g, angle, object, light->color.g);
		color.b = bright(object->color.b, angle, object, light->color.b);
	}
	return (color);
}
