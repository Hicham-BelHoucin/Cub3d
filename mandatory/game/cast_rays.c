/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbel-hou <hbel-hou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 10:54:08 by hbel-hou          #+#    #+#             */
/*   Updated: 2022/07/28 14:22:07 by hbel-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Cub3d.h"

char	has_wall(t_window *conf, double x, double y)
{
	int	mapindexx;
	int	mapindexy;

	if (x < 0 || x > (conf->map_x * 64) || y < 0 || y > (conf->map_y * 64))
		return ('8');
	mapindexx = floor(x / TILE_SIZE);
	mapindexy = floor(y / TILE_SIZE);
	if (mapindexy == conf->map_y)
		return ('1');
	return (conf->map[mapindexy][mapindexx]);
}

double	hoz_intersection(t_window *conf, double _ang)
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
	hoz_intersection_helper(conf);
	if (conf->ray.foundhorwallhit)
		return (disbtp(conf->player.px, conf->player.py,
				conf->ray.horwallhitx, conf->ray.horwallhity));
	return (DBL_MAX);
}

double	ver_intersection(t_window *conf, double _ang)
{
	conf->ray.xintercept = floor(conf->player.px / TILE_SIZE) * TILE_SIZE;
	conf->ray.xintercept += ternary(conf->ray.facingright, TILE_SIZE, 0);
	conf->ray.yintercept = conf->player.py
		+ (conf->ray.xintercept - conf->player.px) * tan(_ang);
	conf->ray.xstep = TILE_SIZE;
	conf->ray.xstep *= ternary(conf->ray.facingleft, -1, 1);
	conf->ray.ystep = TILE_SIZE * tan(_ang);
	conf->ray.ystep *= ternary(
			(conf->ray.facingup && conf->ray.ystep > 0), -1, 1);
	conf->ray.ystep *= ternary(
			(conf->ray.facingdown && conf->ray.ystep < 0), -1, 1);
	conf->ray.nextverx = conf->ray.xintercept;
	conf->ray.nextvery = conf->ray.yintercept;
	ver_intersection_helper(conf);
	if (conf->ray.foundverwallhit)
		return (disbtp(conf->player.px, conf->player.py,
				conf->ray.verwallhitx, conf->ray.verwallhity));
	return (DBL_MAX);
}

void	check_intersection(t_window *conf, double _ang, int i)
{
	set_up_all(conf);
	_ang = normalize_ang(_ang);
	rayfacing(conf, _ang);
	conf->wall.faceleft[i] = conf->ray.facingleft;
	conf->wall.faceright[i] = conf->ray.facingright;
	conf->wall.faceup[i] = conf->ray.facingup;
	conf->wall.facedown[i] = conf->ray.facingdown;
	conf->ray.hordist = hoz_intersection(conf, _ang);
	conf->ray.verdist = ver_intersection(conf, _ang);
	if (conf->ray.verdist > conf->ray.hordist)
	{
		conf->ray.wallhitx = conf->ray.horwallhitx;
		conf->ray.wallhity = conf->ray.horwallhity;
		conf->ray.distance = conf->ray.hordist;
		conf->ray.washitvert = 0;
	}
	else
	{
		conf->ray.wallhitx = conf->ray.verwallhitx;
		conf->ray.wallhity = conf->ray.verwallhity;
		conf->ray.distance = conf->ray.verdist;
		conf->ray.washitvert = 1;
	}
}

void	cast_rays(t_window *conf)
{
	double	_ang;
	int		i;

	i = 0;
	_ang = conf->player.rotangle - (FOV / 2);
	while (i < conf->ray.num_rays)
	{
		_ang = normalize_ang(_ang);
		check_intersection(conf, _ang, i);
		_ang += FOV / conf->ray.num_rays;
		conf->ray.rayangle[i] = _ang;
		conf->wall.line_distance[i] = conf->ray.distance;
		conf->wall.wx[i] = conf->ray.wallhitx;
		conf->wall.wy[i] = conf->ray.wallhity;
		conf->wall.hitver[i] = conf->ray.washitvert;
		i++;
	}
}
