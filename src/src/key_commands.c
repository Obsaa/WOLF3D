/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_commands.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdalha <oabdalha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 13:29:11 by oabdalha          #+#    #+#             */
/*   Updated: 2017/10/16 16:31:25 by oabdalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf3d.h"

int		key_press(int key, t_env *env)
{
	if (key == KEY_ESC)
	{
		free(env);
		exit_key(key, env);
		exit(0);
	}
	if (key == KEY_W || key == KEY_A || key == KEY_D || key == KEY_S ||
						key == KEY_LAR || key == KEY_RAR)
	{
		if (key == KEY_W || key == KEY_S)
			win_s(key, env);
		if (key == KEY_A || key == KEY_D)
			strafe(key, env);
		if (key == KEY_LAR || key == KEY_RAR)
			turn_x_y(key, env);
		ray_casting(env);
	}
	if (key == ONE || key == TWO || key == THREE || key == FOUR || key == FIVE)
		music(key);
	if (key == SIX)
		system("killall afplay");
	return (0);
}

void	turn_x_y(int key, t_env *env)
{
	if (key == KEY_LAR)
		env->player.angle += TURNSPEED;
	if (key == KEY_RAR)
		env->player.angle -= TURNSPEED;
}

int		exit_key(int key, t_env *env)
{
	(void)env;
	(void)key;
	exit(0);
}

void	music(int key)
{
	system("killall afplay");
	if (key == ONE)
		system("afplay music/Super_Mario_Bros.mp3&");
	if (key == TWO)
		system("afplay music/A_Ha_Take_On_Me.mp3&");
	if (key == THREE)
		system("afplay music/Kola_Kid_Press_Start.mp3&");
	if (key == FOUR)
		system("afplay music/Super_Mario_Bros_Remix.mp3&");
	if (key == FIVE)
		system("afplay music/Kola_Kid_2punk2suck.mp3&");
}

void	strafe(int key, t_env *env)
{
	int		move_y;
	int		move_x;

	move_x = cos(env->player.angle - (M_PI / 2)) * MOVESPEED;
	move_y = sin(env->player.angle - (M_PI / 2)) * MOVESPEED;
	if (key == KEY_A)
	{
		if (!check_grid(env->player.pos_x, env->player.pos_y +
					(COLLISION * move_y), env))
			env->player.pos_y += move_y;
		if (!check_grid(env->player.pos_x - (COLLISION * move_x),
					env->player.pos_y, env))
			env->player.pos_x -= move_x;
	}
	if (key == KEY_D)
	{
		if (!check_grid(env->player.pos_x, env->player.pos_y -
					(COLLISION * move_y), env))
			env->player.pos_y -= move_y;
		if (!check_grid(env->player.pos_x + (COLLISION * move_x),
					env->player.pos_y, env))
			env->player.pos_x += move_x;
	}
}

void	win_s(int key, t_env *env)
{
	int		move_y;
	int		move_x;

	move_x = cos(env->player.angle) * MOVESPEED;
	move_y = sin(env->player.angle) * MOVESPEED;
	if (key == KEY_W)
	{
		if (!check_grid(env->player.pos_x, env->player.pos_y -
					(COLLISION * move_y), env))
			env->player.pos_y -= move_y;
		if (!check_grid(env->player.pos_x + (COLLISION * move_x),
					env->player.pos_y, env))
			env->player.pos_x += move_x;
	}
	if (key == KEY_S)
	{
		if (!check_grid(env->player.pos_x, env->player.pos_y +
					(COLLISION * move_y), env))
			env->player.pos_y += move_y;
		if (!check_grid(env->player.pos_x - (COLLISION * move_x),
					env->player.pos_y, env))
			env->player.pos_x -= move_x;
	}
}
