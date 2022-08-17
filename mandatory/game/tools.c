/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbel-hou <hbel-hou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 11:40:52 by hbel-hou          #+#    #+#             */
/*   Updated: 2022/07/27 15:11:38 by hbel-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Cub3d.h"

double	disbtp(double x1, double y1, double x2, double y2)
{
	return (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}

void	rayfacing(t_window *conf, double _ang)
{
	conf->ray.facingdown = (_ang > 0 && _ang < PI);
	conf->ray.facingup = !conf->ray.facingdown;
	conf->ray.facingright = (_ang < 0.5 * PI || _ang > 1.5 * PI);
	conf->ray.facingleft = !conf->ray.facingright;
}

double	normalize_ang(double angle)
{
	angle = remainder(angle, (2 * M_PI));
	if (angle < 0)
		angle = (2 * PI) + angle;
	return (angle);
}

void	hoz_intersection_helper(t_window *conf)
{
	while (conf->ray.nexthox >= 0 && conf->ray.nexthox
		<= (conf->map_x * 64) && conf->ray.nexthoy >= 0
		&& conf->ray.nexthoy <= (conf->map_y * 64))
	{
		conf->ray.xhortocheck = conf->ray.nexthox;
		conf->ray.facingup = int_ternary(conf->ray.facingup, 1, 0);
		conf->ray.yhortocheck = conf->ray.nexthoy - conf->ray.facingup;
		if (has_wall(conf, conf->ray.xhortocheck,
				conf->ray.yhortocheck) == '1')
		{
			conf->ray.foundhorwallhit = 1;
			conf->ray.horwallhitx = conf->ray.nexthox;
			conf->ray.horwallhity = conf->ray.nexthoy;
			break ;
		}
		else
		{
			conf->ray.nexthox += conf->ray.xstep;
			conf->ray.nexthoy += conf->ray.ystep;
		}
	}
}

void	ver_intersection_helper(t_window *conf)
{
	while (conf->ray.nextverx >= 0 && conf->ray.nextverx
		<= (conf->map_x * 64) && conf->ray.nextvery >= 0
		&& conf->ray.nextvery <= (conf->map_y * 64))
	{
		conf->ray.facingleft = int_ternary(conf->ray.facingleft, 1, 0);
		conf->ray.xvertocheck = conf->ray.nextverx - conf->ray.facingleft;
		conf->ray.yvertocheck = conf->ray.nextvery;
		if (has_wall(conf, conf->ray.xvertocheck,
				conf->ray.yvertocheck) == '1')
		{
			conf->ray.verwallhitx = conf->ray.nextverx;
			conf->ray.verwallhity = conf->ray.nextvery;
			conf->ray.foundverwallhit = 1;
			break ;
		}
		else
		{
			conf->ray.nextverx += conf->ray.xstep;
			conf->ray.nextvery += conf->ray.ystep;
		}
	}
}
