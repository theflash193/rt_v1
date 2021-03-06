/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/11 11:57:13 by grass-kw          #+#    #+#             */
/*   Updated: 2016/04/11 12:07:11 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_v1.h"

int		new_color(t_color rgb)
{
	return (rgb.r * pow(16, 4) + rgb.g * pow(16, 2)) + rgb.b;
}
