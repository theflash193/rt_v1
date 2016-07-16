/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 16:03:37 by grass-kw          #+#    #+#             */
/*   Updated: 2016/07/16 06:04:41 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_v1.h"

void	draw(t_env *e)
{
	int		i;
	int		j;
	t_color color;
	int		rgb;

	i = 0;
	while (i++ < LENGHT)
	{
		j = 0;
		while (j++ < WIDTH)
		{
			e->ray = new_vector(500, (LENGHT / 2) - i, (WIDTH / 2) - j);
			rotation(&(e->ray), e->start.angle);
			e->ray = normalize(e->ray);
			color = raytracer(e, e->start.origin, e->ray);
			rgb = new_color(color);
			set_pixel(e, rgb, i, j);
		}
	}
}
