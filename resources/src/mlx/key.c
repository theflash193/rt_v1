/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/10 07:07:36 by grass-kw          #+#    #+#             */
/*   Updated: 2016/05/28 20:06:30 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_v1.h"

int		key(int key, t_env *e)
{
	if (key == 53)
	{
		mlx_destroy_image(e->mlx, e->img);
		clean_env(e);
		exit(0);
	}
	return (0);
}
