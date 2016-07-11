/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_object.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/28 17:52:31 by grass-kw          #+#    #+#             */
/*   Updated: 2016/05/28 17:54:16 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_v1.h"

int	is_object(char *s)
{
	return (ft_strequ_uci("sphere", s) ||
		ft_strequ_uci("plan", s) ||
		ft_strequ_uci("cone", s) ||
		ft_strequ_uci("cylindre", s));
}
