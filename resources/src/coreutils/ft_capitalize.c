/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_capitalize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/24 09:06:27 by grass-kw          #+#    #+#             */
/*   Updated: 2016/07/09 14:44:13 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_v1.h"

static void	must_capitalize(char *s)
{
	*s = ft_toupper(*s);
}

char		*ft_capitalize(char *s)
{
	char *ret;

	ret = ft_strdup(s);
	ft_striter(ret, must_capitalize);
	return (ret);
}
