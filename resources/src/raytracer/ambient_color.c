/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/27 16:00:43 by grass-kw          #+#    #+#             */
/*   Updated: 2016/06/27 17:07:59 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_v1.h"

t_color		ambient_color(t_obj *object)
{
	t_color color;

	color.r = object->color.r * object->material.ka;
	color.g = object->color.g * object->material.ka;
	color.b = object->color.b * object->material.ka;
	return (color);
}
