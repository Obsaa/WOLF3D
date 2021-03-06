/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdalha <oabdalha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 13:44:36 by oabdalha          #+#    #+#             */
/*   Updated: 2017/10/19 11:31:36 by oabdalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H
# include "../libmlx/mlx.h"
# include "../libft/libft.h"
# include <sys/fcntl.h>
# include <math.h>
# include <stdarg.h>
# include <limits.h>

# define SCALE (64 * 4096)
# define TURNSPEED M_PI / 128
# define MOVESPEED SCALE / 16
# define COLLISION 1

# define WIN_W 2048
# define WIN_H 1024
# define FOV M_PI / 3
# define KEY_ESC 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_LAR 123
# define KEY_RAR 124

# define ONE 83
# define TWO 84
# define THREE 85
# define FOUR 86
# define FIVE 87
# define SIX 88

typedef struct	s_key
{
	int			w;
	int			s;
	int			a;
	int			d;
	int			lar;
	int			rar;
}				t_key;

typedef struct	s_v
{
	int			x;
	int			y;
	int			d;
}				t_v;

typedef struct	s_h
{
	int			x;
	int			y;
	int			d;
}				t_h;

typedef struct	s_player
{
	int			pos_x;
	int			pos_y;
	double		angle;
}				t_player;

typedef struct	s_map
{
	int			len;
	int			width;
	int			**grid;
}				t_map;

typedef struct	s_env
{
	t_key		key;
	t_h			h;
	t_v			v;
	t_player	player;
	t_map		map;
	void		*mlx;
	void		*win;
	void		*img;
	int			*pixels;
	int			bpp;
	int			sl;
	int			endian;
	int			ww;
	int			wh;
	char		*name;
	int			block;
	int			drawn;
	int			wallcolor;
}				t_env;
/*
** -------------------- main.c -----------------------
*/
int				main(int ac, char **av);
/*
** -------------------- read.c -----------------------
*/
void			read_map(t_env *env, int fd);
void			store_map(t_env *env, int fd);
void			print_map(t_env *env);
void			error(void);
/*
** -------------------- draw.c -----------------------
*/
void			open_mlx(t_env *env);
void			draw_block(t_env *env, int col);
int				check_grid(int x, int y, t_env *env);
/*
** ----------------- key_commands.c ------------------
*/
int				key_press(int key, t_env *env);
void			turn_x_y(int key, t_env *env);
int				exit_key(int key, t_env *env);
void			strafe(int key, t_env *env);
void			win_s(int key, t_env *env);
void			music(int key);
/*
** ----------------- ray_casting.c -------------------
*/
void			wall_color(t_env *env, double angle);
void			horizontal_ray(t_env *env, double angle);
void			vertical_ray(t_env *env, double angle);
void			ray_casting(t_env *env);
void			clear_pixels(t_env *env);
/*
** --------------------- init.c ----------------------
*/
t_env			*init_env(void);
void			init_player(t_env *env);
void			init_map(t_env *env);
void			init_vh(t_env *env);
void			init_key(t_env *env);
#endif
