/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 15:38:24 by grass-kw          #+#    #+#             */
/*   Updated: 2016/06/23 16:00:29 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_v1.h"

double	resolve(double delta, double a, double b)
{
	double k;
	double k1;
	double k2;

	if (delta > ZERO)
	{
		k1 = ((b * -1) + sqrt(delta)) / (2 * a);
		k2 = ((b * -1) - sqrt(delta)) / (2 * a);
		k = (k1 > ZERO) ? k1 : ZERO;
		k = (k2 > ZERO && k2 < k1) ? k2 : k1;
		return (k);
	}
	return (ZERO);
}
