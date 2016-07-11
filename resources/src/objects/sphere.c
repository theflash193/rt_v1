/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 15:41:11 by grass-kw          #+#    #+#             */
/*   Updated: 2016/06/28 21:03:06 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_v1.h"

double			sphere(t_obj obj, t_vector3d start, t_vector3d ray)
{
	double a;
	double b;
	double c;
	double delta;

	a = pow(ray.x, 2) + pow(ray.y, 2) + pow(ray.z, 2);
	b = 2 * ((start.x - obj.origin.x) * ray.x + (start.y - obj.origin.y) *
		ray.y + (start.z - obj.origin.z) * ray.z);
	c = pow((start.x - obj.origin.x), 2) +
		pow((start.y - obj.origin.y), 2) + pow((start.z - obj.origin.z), 2)
		- pow(obj.size, 2);
	delta = pow(b, 2) - (4 * a * c);
	return (resolve(delta, a, b));
}
