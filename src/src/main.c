/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdalha <oabdalha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 13:47:10 by oabdalha          #+#    #+#             */
/*   Updated: 2017/10/16 17:11:11 by oabdalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf3d.h"

int		main(int ac, char **av)
{
	t_env	*env;
	int		fd;

	if (ac != 2)
	{
		ft_putstr("\033[31mINVALID NUMBER OF ARGUMENTS!\033[0m\n");
		ft_putstr("\033[31mmap/test.map || map/simple.map || m\
ap/medium.map\033[0m\n");
		return (-1);
	}
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("\033[31mOPEN FAILED!\033[0m\n");
		ft_putstr("\033[31mmap/test.map || map/simple.map || m\
ap/medium.map\033[0m\n");
		return (-1);
	}
	env = init_env();
	read_map(env, fd);
	store_map(env, fd);
	print_map(env);
	open_mlx(env);
	return (0);
}
