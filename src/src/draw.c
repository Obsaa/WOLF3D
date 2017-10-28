/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdalha <oabdalha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 12:03:47 by oabdalha          #+#    #+#             */
/*   Updated: 2017/10/17 18:25:12 by oabdalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf3d.h"

void	open_mlx(t_env *env)
{
	env->mlx = mlx_init();
	env->win = mlx_new_window(env->mlx, env->ww, env->wh, env->name);
	env->img = mlx_new_image(env->mlx, WIN_W, WIN_H);
	env->pixels = (int*)mlx_get_data_addr(env->img, &env->bpp, &env->sl,
																&env->endian);
	ray_casting(env);
	mlx_hook(env->win, 2, 0, key_press, env);
	mlx_hook(env->win, 17, 0, exit_key, env);
	mlx_loop(env->mlx);
}

int		check_grid(int x, int y, t_env *env)
{
	x /= SCALE;
	y /= SCALE;
	if (x >= env->map.width || y >= env->map.len || x < 0 || y < 0)
		return (-1);
	return (env->map.grid[y][x]);
}

void	draw_block(t_env *env, int col)
{
	int i;
	int y;
	int floor;

	if (env->block > WIN_H)
		env->block = WIN_H;
	y = (WIN_H / 2) - (env->block / 2);
	floor = y + env->block;
	i = 0;
	while (i < y)
	{
		env->pixels[col + (i * WIN_W)] = 0Xadc5ed;
		i++;
	}
	while (y < floor)
	{
		if (y >= 0 && y < WIN_H)
			env->pixels[col + (y * WIN_W)] = env->wallcolor;
		y++;
	}
	while (y < WIN_H)
	{
		env->pixels[col + (y * WIN_W)] = 0x567c58;
		y++;
	}
}
