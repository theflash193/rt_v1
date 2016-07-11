/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 14:13:34 by grass-kw          #+#    #+#             */
/*   Updated: 2016/07/09 16:20:08 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_v1.h"

static void	parse_type_argument(char **tab, t_env *e)
{
	if (is_object(tab[0]))
		parser_object(tab, e);
	else if (is_light(tab[0]))
		parser_light(tab, e);
	else if (is_camera(tab[0]))
		parser_camera(tab, e);
	else
		ft_exit("unvalided format", e);
}

void		parser(t_env *e, char *argument)
{
	int		fd;
	char	*line;
	char	**tab;

	line = NULL;
	if ((fd = open(argument, O_RDONLY)) < 0)
		ft_exit("invalid file", e);
	while (get_next_line(fd, &line))
	{
		tab = ft_strsplit_spc(line);
		parse_type_argument(tab, e);
		ft_free_tab(tab);
		ft_strclean(line);
	}
}
