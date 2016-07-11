/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/10 06:24:29 by grass-kw          #+#    #+#             */
/*   Updated: 2016/07/09 14:42:07 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_v1.h"

void	create_window(char *argument)
{
	t_env e;

	ft_bzero(&e, sizeof(t_env));
	parser(&e, argument);
	env_setup(&e);
	draw(&e);
	mlx_key_hook(e.win, key, &e);
	mlx_expose_hook(e.win, expose, &e);
	mlx_loop(e.mlx);
}

int		main(int ac, char **av)
{
	if (ac == 2)
		create_window(av[1]);
	else
		msg_usage();
	return (0);
}
