/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbel-hou <hbel-hou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 12:45:11 by hbel-hou          #+#    #+#             */
/*   Updated: 2022/08/03 15:28:24 by hbel-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Cub3d.h"

void	set_players_position(int *x, int *y, char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (ft_strchr("SEWN", map[i][j]))
			{
				*y = i;
				*x = j;
			}
			j++;
		}
		i++;
	}
	return ;
}

void	init_all(t_window *conf)
{
	int	i;

	i = -1;
	while (++i < 4)
		conf->elem[i].texture = load_img(conf->elem[i].path, conf->mlx);
	conf->player.dxx = 0;
	conf->player.dyy = 0;
	set_players_position(&conf->player.dxx, &conf->player.dyy, conf->map);
	conf->player.py = conf->player.dyy * 64 + 64 / 2;
	conf->player.px = conf->player.dxx * 64 + 64 / 2;
	set_rotangle(&conf->player.rotangle,
		conf->map[conf->player.dyy][conf->player.dxx]);
	conf->player.movespeed = 5;
	conf->player.rotspeed = 2 * (PI / 180);
	conf->player.tdirection = 0;
	conf->player.walkdirection = 0;
	conf->player.to_a = 0;
	conf->player.to_w = 0;
	conf->player.to_s = 0;
	conf->player.to_d = 0;
	conf->player.to_back = 0;
	conf->player.to_forward = 0;
	conf->ray.num_rays = WIDTH;
	conf->map_x = ft_strlen(conf->map[0]);
	conf->map_y = ft_arr_length(conf->map);
}

void	set_up_all(t_window *conf)
{
	conf->ray.horwallhitx = 0;
	conf->ray.horwallhity = 0;
	conf->ray.verwallhitx = 0;
	conf->ray.verwallhity = 0;
	conf->map_x = ft_strlen(conf->map[0]);
	conf->map_y = ft_arr_length(conf->map);
	conf->ray.xstep = 0;
	conf->ray.ystep = 0;
	conf->ray.xintercept = 0;
	conf->ray.yintercept = 0;
	conf->ray.nexthox = 0;
	conf->ray.nexthoy = 0;
	conf->ray.nextverx = 0;
	conf->ray.nextvery = 0;
	conf->ray.foundhorwallhit = 0;
	conf->ray.foundverwallhit = 0;
	conf->ray.verdist = 0;
	conf->ray.hordist = 0;
	conf->ray.washitvert = 0;
	conf->txtnbr = 0;
	conf->r = 0;
}

void	set_rotangle(double *rot, char c)
{
	if (c == 'N')
		*rot = (PI * 3) / 2;
	if (c == 'S')
		*rot = PI / 2;
	if (c == 'E')
		*rot = 2 * PI;
	if (c == 'W')
		*rot = PI;
}

void	get_filled_map(char **map)
{
	int		length;
	char	*temp;
	int		i;
	int		j;

	i = -1;
	length = ft_strlen(map[++i]);
	while (map[++i])
		if ((int)ft_strlen(map[i]) > length)
			length = ft_strlen(map[i]);
	i = -1;
	while (map[++i])
	{
		temp = (char *)malloc(sizeof(char) * length + 1);
		j = -1;
		while (map[i][++j])
			temp[j] = map[i][j];
		while (j < length)
			temp[j++] = '1';
		temp[j] = '\0';
		free(map[i]);
		map[i] = ft_strdup(temp);
		free(temp);
	}
	return ;
}
