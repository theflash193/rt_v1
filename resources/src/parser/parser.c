/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 14:13:34 by grass-kw          #+#    #+#             */
/*   Updated: 2016/07/20 11:15:34 by grass-kw         ###   ########.fr       */
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

static int	is_file(char *path)
{
	struct stat buf;
	int			ret;

	if ((ret = lstat(path, &buf)) == -1)
	{
		perror("error");
		return (0);
	}
	if (buf.st_mode & S_IFMT && !(buf.st_mode & S_IFDIR))
		return (1);
	return (0);
}

void		parser(t_env *e, char *argument)
{
	int		fd;
	char	*line;
	char	**tab;

	line = NULL;
	if (is_file(argument) == 0)
		ft_exit("invalid file", e);
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
