/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 23:30:00 by grass-kw          #+#    #+#             */
/*   Updated: 2016/06/28 21:02:42 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_v1.h"

double	inter(t_obj *obj, t_vector3d *start, t_vector3d *ray)
{
	double result;

	result = ZERO;
	if (obj->type == SPHERE)
		result = sphere(*obj, *start, *ray);
	if (obj->type == PLAN)
		result = plan(*obj, *start, *ray);
	if (obj->type == CYLINDRE)
		result = cylindre(*obj, *start, *ray);
	if (obj->type == CONE)
		result = cone(*obj, *start, *ray);
	return (result);
}
