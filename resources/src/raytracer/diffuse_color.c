/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diffuse_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/27 15:09:58 by grass-kw          #+#    #+#             */
/*   Updated: 2016/06/27 15:59:30 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_v1.h"

double		diffuse_light(t_vector3d a, t_vector3d b)
{
	return (dot_product(a, b) /
		sqrt((pow(a.x, 2) + pow(a.y, 2) + pow(a.z, 2)) *
		(pow(b.x, 2) + pow(b.y, 2) + pow(b.z, 2))));
}

double		bright(double color, double cosa, t_obj *object)
{
	return (color * cosa * object->material.kd);
}

t_color		diffuse_color(t_obj *light, t_vector3d n, t_obj *object)
{
	t_color	color;
	double	angle;

	angle = diffuse_light(n, light->l);
	color = set_rgb(0, 0, 0);
	if (angle >= 0)
	{
		color.r = bright(object->color.r, angle, object);
		color.g = bright(object->color.g, angle, object);
		color.b = bright(object->color.b, angle, object);
	}
	return (color);
}
