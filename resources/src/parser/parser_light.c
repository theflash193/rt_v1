/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_light.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/24 08:45:41 by grass-kw          #+#    #+#             */
/*   Updated: 2016/05/28 21:18:15 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_v1.h"

void	parser_light(char **tab, t_env *e)
{
	t_obj	spot;

	if (check_tab_is_valid(tab) == 0)
		ft_exit("too few argument", e);
	ft_bzero(&spot, sizeof(t_obj));
	spot.type = SPOT;
	spot.origin = new_vector(atof(tab[1]), atof(tab[2]), atof(tab[3]));
	spot.color = set_rgb(atoi(tab[4]), atoi(tab[5]), atoi(tab[6]));
	ft_lstadd(&(e->list_spot), ft_lstnew(&spot, sizeof(t_obj)));
}
