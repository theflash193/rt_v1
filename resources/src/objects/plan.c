/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plan.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 15:49:59 by grass-kw          #+#    #+#             */
/*   Updated: 2016/07/08 16:18:21 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_v1.h"

double	plan(t_obj obj, t_vector3d start, t_vector3d ray)
{
	double k;

	k = -(-obj.origin.x * start.x + obj.origin.y * start.y + obj.origin.z
		* start.z + obj.size) / (-obj.origin.x * ray.x + obj.origin.y
		* ray.y + obj.origin.z * ray.z);
	if (k > ZERO)
		return (k);
	return (ZERO);
}
