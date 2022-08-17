/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imabid <imabid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 13:58:33 by hbel-hou          #+#    #+#             */
/*   Updated: 2022/08/15 12:24:51 by imabid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3d_bonus.h"

void	hoz_intersection_helper_bonus1(t_window *conf)
{
	conf->ray.foundhorwallhit = 1;
	conf->ray.horwallhitx = conf->ray.nexthox;
	conf->ray.horwallhity = conf->ray.nexthoy;
	if ((int)floor(conf->ray.yhortocheck / TILE_SIZE) == conf->map_y)
	{
		conf->ray.horwallcontent = '1';
		return ;
	}
	conf->ray.horwallcontent = conf->old_map[(int)floor(
			conf->ray.yhortocheck / TILE_SIZE)][(int)floor(
			conf->ray.xhortocheck / TILE_SIZE)];
}

void	hoz_intersection_helper_bonus(t_window *conf)
{
	while (conf->ray.nexthox >= 0 && conf->ray.nexthox
		<= (conf->map_x * 64) && conf->ray.nexthoy >= 0
		&& conf->ray.nexthoy <= (conf->map_y * 64))
	{
		conf->ray.xhortocheck = conf->ray.nexthox;
		conf->ray.facingup = int_ternary(conf->ray.facingup, 1, 0);
		conf->ray.yhortocheck = conf->ray.nexthoy - conf->ray.facingup;
		if (has_wall(conf, conf->ray.xhortocheck,
				conf->ray.yhortocheck) == '1'
			|| has_wall(conf, conf->ray.xhortocheck,
				conf->ray.yhortocheck) == '2')
		{
			hoz_intersection_helper_bonus1(conf);
			break ;
		}
		else
		{
			conf->ray.nexthox += conf->ray.xstep;
			conf->ray.nexthoy += conf->ray.ystep;
		}
	}
}

void	ver_intersection_helper_bonus1(t_window *conf)
{
	conf->ray.verwallhitx = conf->ray.nextverx;
	conf->ray.verwallhity = conf->ray.nextvery;
	conf->ray.foundverwallhit = 1;
	conf->ray.verwallcontent = conf->map[(int)floor(
			conf->ray.yvertocheck / TILE_SIZE)][(int)floor(
			conf->ray.xvertocheck / TILE_SIZE)];
}

void	ver_intersection_helper_bonus(t_window *conf)
{
	while (conf->ray.nextverx >= 0 && conf->ray.nextverx
		<= (conf->map_x * 64) && conf->ray.nextvery >= 0
		&& conf->ray.nextvery <= (conf->map_y * 64))
	{
		conf->ray.facingleft = int_ternary(conf->ray.facingleft, 1, 0);
		conf->ray.xvertocheck = conf->ray.nextverx - conf->ray.facingleft;
		conf->ray.yvertocheck = conf->ray.nextvery;
		if (has_wall(conf, conf->ray.xvertocheck,
				conf->ray.yvertocheck) == '1'
			|| has_wall(conf, conf->ray.xvertocheck,
				conf->ray.yvertocheck) == '2')
		{
			ver_intersection_helper_bonus1(conf);
			break ;
		}
		else
		{
			conf->ray.nextverx += conf->ray.xstep;
			conf->ray.nextvery += conf->ray.ystep;
		}
	}
}

void	put_pixle(t_window *conf, int y, int offsetx, int offsety)
{
	int	color;
	int	texnm;

	texnm = conf->wall.con[conf->wall.drawstartx];
	color = conf->elem[conf->txtnbr]
		.texture.addr[(offsety * TEX_WIDTH) + offsetx];
	if (texnm == '2')
		color = conf->door.addr[(offsety * TEX_WIDTH) + offsetx];
	conf->addr[((y) * WIDTH
			+ (conf->wall.drawstartx))] = color;
}
