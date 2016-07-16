/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 15:30:03 by grass-kw          #+#    #+#             */
/*   Updated: 2016/07/16 03:18:43 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_v1.h"

// static void	rotation_x(t_vector3d *a, double angle)
// {
// 	double tmp_x;
// 	double tmp_y;
// 	double tmp_z;

// 	if (angle != ZERO)
// 	{
// 		tmp_x = a->x;
// 		tmp_y = (cos(angle) * a->y) + (-sin(angle) * a->z);
// 		tmp_z = (sin(angle) * a->y) + (cos(angle) * a->z);
// 		a->x = tmp_x;
// 		a->y = tmp_y;
// 		a->z = tmp_z;
// 	}
// }

// static void	rotation_y(t_vector3d *a, double angle)
// {
// 	double tmp_x;
// 	double tmp_y;
// 	double tmp_z;

// 	if (angle != ZERO)
// 	{
// 		tmp_x = (cos(angle) * a->x) + (sin(angle) * a->z);
// 		tmp_y = a->y;
// 		tmp_z = (-sin(angle) * a->x) + (cos(angle) * a->z);
// 		a->x = tmp_x;
// 		a->y = tmp_y;
// 		a->z = tmp_z;
// 	}
// }

// static void	rotation_z(t_vector3d *a, double angle)
// {
// 	double tmp_x;
// 	double tmp_y;
// 	double tmp_z;

// 	if (angle != ZERO)
// 	{
// 		tmp_x = cos(angle) * a->x - sin(angle) * a->y;
// 		tmp_y = sin(angle) * a->x + cos(angle) * a->y;
// 		tmp_z = a->z;
// 		a->x = tmp_x;
// 		a->y = tmp_y;
// 		a->z = tmp_z;
// 	}
// }

// void		rotation_inverse(t_vector3d *a, t_vector3d angle)
// {
// 	rotation_x(a, (-1) * angle.x);
// 	rotation_y(a, (-1) * angle.y);
// 	rotation_z(a, (-1) * angle.z);
// }

// void		rotation(t_vector3d *a, t_vector3d angle)
// {
// 	rotation_x(a, angle.x);
// 	rotation_y(a, angle.y);
// 	rotation_z(a, angle.z);
// }

void	rotation(t_vector3d *vec, t_vector3d angle)
{
	t_vector3d	tmp;
	double		sinx;
	double		siny;
	double		sinz;

	if (angle.x || angle.y || angle.z)
	{
		sinx = sin(angle.x);
		siny = sin(angle.y);
		sinz = sin(angle.z);
		angle.x = cos(angle.x);
		angle.y = cos(angle.y);
		angle.z = cos(angle.z);
		tmp.x = vec->x;
		tmp.y = vec->y;
		tmp.z = vec->z;
		vec->x = tmp.x * angle.y * angle.z - tmp.y * angle.y * sinz + tmp.z * siny;
		vec->y = tmp.x * (angle.x * sinz + sinx * siny * angle.z) + tmp.y *
			(angle.x * angle.z - sinx * siny * sinz) - tmp.z * sinx *
			angle.y;
		vec->z = tmp.x * (sinx * sinz - angle.x * siny * angle.z) + tmp.y *
			(sinx * angle.z + angle.x * siny * sinz) + tmp.z * angle.x *
			angle.y;
	}
	// return (vec);
}
