/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 15:56:57 by grass-kw          #+#    #+#             */
/*   Updated: 2016/07/16 02:49:48 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_v1.h"

double			cone(t_obj obj, t_vector3d start, t_vector3d ray)
{
	double a;
	double b;
	double c;
	double delta;

	rotation(&(obj.origin), obj.angle);
	rotation(&(start), obj.angle);
	rotation(&(ray), obj.angle);
	a = pow(ray.x, 2) + pow(ray.y, 2) - pow(ray.z, 2);
	b = 2 * ((start.x - obj.origin.x) * ray.x + (start.y - obj.origin.y) *
		ray.y - (start.z - obj.origin.z) * ray.z);
	c = pow((start.x - obj.origin.x), 2) + pow((start.y - obj.origin.y), 2)
		- pow((start.z - obj.origin.z), 2) - obj.size;
	delta = pow(b, 2) - (4 * a * c);
	return (resolve(delta, a, b));
}
