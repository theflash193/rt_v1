/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/28 17:55:48 by grass-kw          #+#    #+#             */
/*   Updated: 2016/05/28 17:56:20 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_v1.h"

void	clean_env(t_env *e)
{
	if (e->list_obj != NULL)
		ft_lstdel(&(e->list_obj), clean_elem);
	if (e->list_spot != NULL)
		ft_lstdel(&(e->list_spot), clean_elem);
}
