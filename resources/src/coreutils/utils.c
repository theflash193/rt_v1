/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 15:34:15 by grass-kw          #+#    #+#             */
/*   Updated: 2016/07/09 14:40:43 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_v1.h"

t_vector3d	new_vector(double x, double y, double z)
{
	t_vector3d pos;

	pos.x = x;
	pos.y = y;
	pos.z = z;
	return (pos);
}

t_color		set_rgb(int r, int g, int b)
{
	t_color rgb;

	(void)rgb;
	rgb.r = r;
	rgb.g = g;
	rgb.b = b;
	return (rgb);
}
