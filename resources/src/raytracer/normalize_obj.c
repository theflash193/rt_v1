/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize_obj.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/21 13:13:12 by grass-kw          #+#    #+#             */
/*   Updated: 2016/07/09 14:47:51 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_v1.h"

static void		normalize_cylindre_cone(t_env *e, t_vector3d *n)
{
	if (e->obj_inter->type == CYLINDRE)
	{
		rotation(&(e->obj_inter->origin), e->obj_inter->angle);
		n->x = e->inter.x - e->obj_inter->origin.x;
		n->y = e->inter.y - e->obj_inter->origin.y;
		n->z = e->inter.z;
		rotation_inverse(&(e->obj_inter->origin), e->obj_inter->angle);
	}
	if (e->obj_inter->type == CONE)
	{
		rotation(&(e->obj_inter->origin), e->obj_inter->angle);
		n->x = e->inter.x - e->obj_inter->origin.x;
		n->y = e->inter.y - e->obj_inter->origin.y;
		n->z = e->inter.z + e->obj_inter->origin.z;
		rotation_inverse(&(e->obj_inter->origin), e->obj_inter->angle);
	}
}

t_vector3d		normalize_obj(t_env *e)
{
	t_vector3d	n;
	t_vector3d	plan;

	if (e->obj_inter->type == SPHERE)
		n = sub_vector(e->obj_inter->origin, e->inter);
	if (e->obj_inter->type == PLAN)
	{
		plan = e->obj_inter->origin;
		n = sub_vector(plan, e->inter);
		n.x *= -1;
	}
	normalize_cylindre_cone(e, &n);
	return (n);
}
