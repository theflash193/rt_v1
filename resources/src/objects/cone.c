/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 15:56:57 by grass-kw          #+#    #+#             */
/*   Updated: 2016/07/19 17:40:58 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_v1.h"

void	print_color(t_color color)
{
	printf("r %d g %d b %d\n", color.r, color.g, color.b);
}

void	print_vector(t_vector3d tab)
{
	printf("vector[%lf, %lf, %lf]\n", tab.x, tab.y, tab.z);
}

void	print_material(t_material mat)
{
	printf("material[%lf, %lf, %lf, %lf, %d, %lf]\n", mat.shine, mat.ka, mat.kd, mat.ks, mat.pow_spec, mat.specular);
}

void	print_obj(t_obj obj)
{
	printf("obj :\n");
	printf("type %d\n", obj.type);
	printf("origin ");
	print_vector(obj.origin);
	printf("size %lf\n", obj.size);
	printf("color ");
	print_color(obj.color);
	printf("angle ");
	print_vector(obj.angle);
	print_material(obj.material);
	printf("vector light ");
	print_vector(obj.l);
}
double			cone(t_obj obj, t_vector3d start, t_vector3d ray)
{
	double a;
	double b;
	double c;
	double delta;
	double angle;

	// print_obj(obj);
	// angle = pow(tan(obj.size * M_PI / 180), 2);
	rotation(&(obj.origin), obj.angle);
	rotation(&(start), obj.angle);
	rotation(&(ray), obj.angle);
	a = pow(ray.x, 2) + pow(ray.y, 2) - pow(ray.z, 2);
	b = 2 * ((start.x - obj.origin.x) * ray.x + (start.y - obj.origin.y) *
		ray.y - (/*angle * */(start.z - obj.origin.z) * ray.z));
	c = pow((start.x - obj.origin.x), 2) + pow((start.y - obj.origin.y), 2)
		- (/*angle * */pow((start.z - obj.origin.z), 2));
	delta = pow(b, 2) - (4 * a * c);
	// rotation_inverse(&(obj.origin), obj.angle);
	// rotation_inverse(&(start), obj.angle);
	// rotation_inverse(&(ray), obj.angle);
	return (resolve(delta, a, b));
}
