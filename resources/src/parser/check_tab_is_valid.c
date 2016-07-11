/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tab_is_valid.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/28 18:05:56 by grass-kw          #+#    #+#             */
/*   Updated: 2016/05/28 18:06:17 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_v1.h"

int	check_tab_is_valid(char **tab)
{
	size_t tab_len;

	tab_len = ft_array_len(tab);
	if (is_object(tab[0]) && (tab_len == 11 || tab_len == 12))
		return (1);
	if (is_light(tab[0]) && tab_len == 7)
		return (1);
	if (is_camera(tab[0]) && tab_len == 7)
		return (1);
	return (0);
}
