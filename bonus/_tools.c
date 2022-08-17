/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _tools.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbel-hou <hbel-hou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 14:00:16 by hbel-hou          #+#    #+#             */
/*   Updated: 2022/07/28 14:34:33 by hbel-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3d_bonus.h"

void	player_print(t_window *conf)
{
	int		r;
	int		i;
	int		j;
	double	x;
	double	y;

	x = conf->player.px;
	y = conf->player.py;
	r = 25;
	i = -r;
	j = 0;
	while (i < r)
	{
		j = -r;
		while (j < r)
		{
			if ((i * i) + (j * j) <= (r * r))
			{
				conf->addr[(int)(((i + y)) * MINIMAP) *WIDTH
					+ (int)(((j + x) * MINIMAP))] = get_color(128, 0, 0);
			}
			j++;
		}
		i++;
	}
}

void	print_rectangl(t_window *conf, int y, int x, int color)
{
	int	i;
	int	j;
	int	line;

	x *= (TILE_SIZE * MINIMAP);
	y *= (TILE_SIZE * MINIMAP);
	i = 0;
	line = 0;
	while (i < (TILE_SIZE - line) * MINIMAP)
	{
		j = 0;
		while (j < (TILE_SIZE - line) * MINIMAP)
		{
			conf->addr[(int)((y + j)) *WIDTH + (int)((x + i))] = color;
			j++;
		}
		i++;
	}
}

void	mapp_print(t_window *conf)
{
	int	i;
	int	j;

	i = 0;
	while (conf->old_map[i])
	{
		j = 0;
		while (conf->old_map[i][j])
		{
			if (conf->old_map[i][j] == '1')
				print_rectangl(conf, i, j, get_color(0, 0, 0));
			else if (conf->old_map[i][j] == '2')
				print_rectangl(conf, i, j, get_color(122, 122, 122));
			j++;
		}
		i++;
	}
}

double	hoz_intersection_bonus(t_window *conf, double _ang)
{
	conf->ray.yintercept = floor(conf->player.py / TILE_SIZE) * TILE_SIZE;
	conf->ray.yintercept += ternary(conf->ray.facingdown, TILE_SIZE, 0);
	conf->ray.xintercept = conf->player.px
		+ (conf->ray.yintercept - conf->player.py) / tan(_ang);
	conf->ray.ystep = TILE_SIZE;
	conf->ray.ystep *= ternary(conf->ray.facingup, -1, 1);
	conf->ray.xstep = TILE_SIZE / tan(_ang);
	conf->ray.xstep *= ternary(
			(conf->ray.facingleft && conf->ray.xstep > 0), -1, 1);
	conf->ray.xstep *= ternary(
			(conf->ray.facingright && conf->ray.xstep < 0), -1, 1);
	conf->ray.nexthox = conf->ray.xintercept;
	conf->ray.nexthoy = conf->ray.yintercept;
	hoz_intersection_helper_bonus(conf);
	if (conf->ray.foundhorwallhit)
		return (disbtp(conf->player.px, conf->player.py,
				conf->ray.horwallhitx, conf->ray.horwallhity));
	return (DBL_MAX);
}

void	try_to_close_door(t_window *conf)
{
	int	i;
	int	j;
	int	x;
	int	y;

	i = 0;
	y = (int)(conf->player.py / TILE_SIZE);
	x = (int)(conf->player.px / TILE_SIZE);
	while (conf->old_map[i])
	{
		j = 0;
		while (conf->old_map[i][j])
		{
			if (conf->old_map[i][j] == '2')
			{
				if (((j != x) && (j + 1 != x && j - 1 != x)))
					conf->map[i][j] = conf->old_map[i][j];
				if (((i != y) && (i + 1 != y && i - 1 != y)))
					conf->map[i][j] = conf->old_map[i][j];
			}
			j++;
		}
		i++;
	}
}
