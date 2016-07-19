/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specular_color.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/27 15:10:43 by grass-kw          #+#    #+#             */
/*   Updated: 2016/07/19 17:31:44 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_v1.h"

double		specular_light(t_vector3d e, t_vector3d r, t_obj *obj)
{
	double	dot;

	dot = dot_product(e, r);
	return (pow(dot, obj->material.pow_spec));
}

double		shine(t_obj *object, double color, double norme)
{
	return (object->material.ks * object->material.shine * color * norme);
}

t_color		specular_color(t_obj *light, t_vector3d n, t_obj *object,
	t_vector3d ray)
{
	t_color		color;
	double		angle;
	t_vector3d	r;
	double		light_normal_dot;
	double		spec;

	light_normal_dot = dot_product(n, light->l);
	color = set_rgb(0, 0, 0);
	r.x = light->l.x - 2 * n.x * light_normal_dot;
	r.y = light->l.y - 2 * n.y * light_normal_dot;
	r.z = light->l.z - 2 * n.z * light_normal_dot;
	angle = dot_product(ray, r);
	if (angle > 0)
	{
		spec = pow(angle, object->material.pow_spec) *
		object->material.shine * object->material.specular *
		object->material.ks;
		color.r = light->color.r * spec;
		color.g = light->color.g * spec;
		color.b = light->color.b * spec;
	}
	return (color);
}
