/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_camera.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/28 17:57:35 by grass-kw          #+#    #+#             */
/*   Updated: 2016/05/28 21:15:19 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_v1.h"

void	parser_camera(char **tab, t_env *e)
{
	if (check_tab_is_valid(tab) == 0)
		ft_exit("too few argument", e);
	ft_bzero(&(e->start), sizeof(t_obj));
	e->start.type = CAMERA;
	e->start.origin = new_vector(atof(tab[1]), atof(tab[2]), atof(tab[3]));
	e->start.angle = new_vector(atof(tab[4]), atof(tab[5]), atof(tab[6]));
}
