/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylindre.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 15:39:19 by grass-kw          #+#    #+#             */
/*   Updated: 2016/06/28 21:54:31 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_v1.h"

double			cylindre(t_obj obj, t_vector3d start, t_vector3d ray)
{
	double a;
	double b;
	double c;
	double delta;

	rotation(&(obj.origin), obj.angle);
	rotation(&(start), obj.angle);
	rotation(&(ray), obj.angle);
	a = ray.x * ray.x + ray.y * ray.y;
	b = 2 * (((start.x - obj.origin.x) * ray.x) +
		((start.y - obj.origin.y) * ray.y));
	c = (start.x - obj.origin.x) * (start.x - obj.origin.x) +
		(start.y - obj.origin.y) * (start.y - obj.origin.y)
		- (obj.size * obj.size);
	delta = b * b - 4 * a * c;
	return (resolve(delta, a, b));
}
