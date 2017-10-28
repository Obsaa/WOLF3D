/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   music.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdalha <oabdalha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 13:47:10 by oabdalha          #+#    #+#             */
/*   Updated: 2017/10/16 17:11:11 by oabdalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf3d.h"

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

void	read_map(t_env *env, int fd)
{
	char	*str;
	int		num[4];
	int		i;
	char	*tmp;

	str = (char*)malloc(sizeof(char) * UINT_MAX);
	tmp = str;
	get_next_line(fd, &str) ? i = 0 : 0;
	while ((*str))
	{
		if (*str == ' ')
			str++;
		else
		{
			num[i] = ft_atoi(str);
			while (*str >= '0' && *str <= '9')
				str++;
			i++;
		}
	}
	env->map.width = num[0];
	env->map.len = num[1];
	env->player.pos_x = (num[2] * SCALE) + (SCALE / 2);
	env->player.pos_y = (num[3] * SCALE) + (SCALE / 2);
	ft_strdel(&tmp);
}
