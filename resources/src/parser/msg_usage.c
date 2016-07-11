/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg_usage.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/28 18:04:21 by grass-kw          #+#    #+#             */
/*   Updated: 2016/07/09 14:43:40 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_v1.h"

void	msg_usage(void)
{
	ft_putendl("Usage : 3 type object [camera, light, object]\n");
	ft_putendl("define camera by : (name[camera]) (origin) (angle)");
	ft_putendl("\tEx : camera -80 0 80 0 0 0\n");
	ft_putendl("define light by : (name[light]) (origin) (color)");
	ft_putendl("\tlight -80 0 80 255 255 255\n");
	ft_putstr("define object by : (name[sphere/plan/cylindre/cone]) (origin)");
	ft_putendl("(color)(size)(angle)(optionel : material[mirror/glass/metal])");
	ft_putendl("\tsphere 0 0 0 255 0 0 100 0 0 0 metal");
}
