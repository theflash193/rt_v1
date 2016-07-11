/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_object.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/28 17:57:05 by grass-kw          #+#    #+#             */
/*   Updated: 2016/06/27 19:12:21 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_v1.h"

static int	parser_material3(char *material, t_obj *object, t_env *e)
{
	if (ft_strequ_uci("default2", material))
	{
		object->material.shine = 0;
		object->material.ka = 0;
		object->material.kd = 0.4;
		object->material.ks = 0.3;
		object->material.pow_spec = 200;
		object->material.specular = 200;
		return (1);
	}
	else
		return (0);
}

static int	parser_material2(char *material, t_obj *object, t_env *e)
{
	if (ft_strequ_uci("mirror", material))
	{
		object->material.shine = 0.5;
		object->material.ka = 0.2;
		object->material.kd = 0.4;
		object->material.ks = 0.4;
		object->material.pow_spec = 0;
		object->material.specular = 0;
		return (1);
	}
	else if (ft_strequ_uci("default", material) || material == NULL)
	{
		object->material.shine = 0.8;
		object->material.ka = 0;
		object->material.kd = 0.4;
		object->material.ks = 0.3;
		object->material.pow_spec = 200;
		object->material.specular = 200;
		return (1);
	}
	else if (parser_material3(material, object, e))
		return (1);
	else
		return (0);
}

void		parser_material(char *material, t_obj *object, t_env *e)
{
	if (ft_strequ_uci("metal", material))
	{
		object->material.shine = 1;
		object->material.ka = 0.2;
		object->material.kd = 0.2;
		object->material.ks = 0.6;
		object->material.pow_spec = 600;
		object->material.specular = 500;
	}
	else if (parser_material2(material, object, e))
		;
	else if (ft_strequ_uci("glass", material))
	{
		object->material.shine = 0.2;
		object->material.ka = 0.3;
		object->material.kd = 0.4;
		object->material.ks = 0.3;
		object->material.pow_spec = 200;
		object->material.specular = 200;
	}
	else
	{
		msg_usage();
		ft_exit("wrong format", e);
	}
}

int			object_type(char *type)
{
	if (ft_strequ_uci("sphere", type))
		return (SPHERE);
	else if (ft_strequ_uci("plan", type))
		return (PLAN);
	else if (ft_strequ_uci("cylindre", type))
		return (CYLINDRE);
	else
		return (CONE);
}

void		parser_object(char **tab, t_env *e)
{
	t_obj	object;
	size_t	tab_len;

	if (check_tab_is_valid(tab) == 0)
		ft_exit("too few argument", e);
	ft_bzero(&object, sizeof(t_obj));
	object.type = object_type(tab[0]);
	object.origin = new_vector(atof(tab[1]), atof(tab[2]), atof(tab[3]));
	object.size = atof(tab[4]);
	object.color = set_rgb(atoi(tab[5]), atoi(tab[6]), atoi(tab[7]));
	object.angle.x = M_PI * (atof(tab[8])) / 180;
	object.angle.y = M_PI * (atof(tab[9])) / 180;
	object.angle.z = M_PI * (atof(tab[10])) / 180;
	tab_len = ft_array_len(tab);
	if (tab_len == 11)
		parser_material(NULL, &object, e);
	else if (tab_len == 12)
		parser_material(tab[11], &object, e);
	ft_lstadd(&(e->list_obj), ft_lstnew(&object, sizeof(t_obj)));
}
