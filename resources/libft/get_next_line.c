/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/04 14:33:27 by grass-kw          #+#    #+#             */
/*   Updated: 2016/07/09 16:25:47 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			final_str(char **line, char *str)
{
	char	*tmp;

	tmp = ft_strchr(str, '\n');
	if (tmp != NULL)
	{
		*tmp = '\0';
		*line = ft_strdup(str);
		ft_memmove(str, &tmp[1], ft_strlen(&tmp[1]) + 1);
		return (1);
	}
	if (ft_strlen(str) > 0)
	{
		*line = ft_strdup(str);
		*str = '\0';
		return (1);
	}
	return (0);
}

int					get_next_line(int const fd, char **line)
{
	char			buff[BUFF_SIZE + 1];
	int				rd;
	static char		*str = NULL;
	char			*tmp;

	if (fd < 0 || !line)
		return (-1);
	if (str == NULL)
		str = (char *)malloc(sizeof(char) * 1);
	if (str == NULL)
		return (-1);
	while (!ft_strchr(str, '\n'))
	{
		rd = read(fd, buff, BUFF_SIZE);
		if (rd == -1)
			return (-1);
		if (rd == 0)
			break ;
		buff[rd] = '\0';
		tmp = ft_strjoin(str, buff);
		free(str);
		str = tmp;
	}
	return (final_str(line, str));
}
