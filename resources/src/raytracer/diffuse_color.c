/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diffuse_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/27 15:09:58 by grass-kw          #+#    #+#             */
/*   Updated: 2016/07/19 17:33:12 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_v1.h"

// vectlum.x * n.x + vectlum.y * n.y + vectlum.z * n.z) /
//        (sqrt(pow(vectlum.x, 2) + pow(vectlum.y, 2) + pow(vectlum.z, 2)) *
//        sqrt(pow(n.x, 2) + pow(n.y, 2) + pow(n.z, 2)));

double		diffuse_light(t_vector3d a, t_vector3d b)
{
	// return (dot_product(a, b) /
	// 	sqrt((pow(a.x, 2) + pow(a.y, 2) + pow(a.z, 2)) *
	// 	(pow(b.x, 2) + pow(b.y, 2) + pow(b.z, 2))));
	return (dot_product(a, b) /
		(
		sqrt((pow(a.x, 2) + pow(a.y, 2) + pow(a.z, 2))) *
		sqrt((pow(b.x, 2) + pow(b.y, 2) + pow(b.z, 2)))
		));
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

	// light->l = normalize(light->l);
	angle = diffuse_light(n, light->l);
	color = set_rgb(0, 0, 0);
	// if (angle >= 0)
	// {
		color.r = bright(object->color.r, angle, object, light->color.r);
		color.g = bright(object->color.g, angle, object, light->color.g);
		color.b = bright(object->color.b, angle, object, light->color.b);
	// }
	return (color);
}
