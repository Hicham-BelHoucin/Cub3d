/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imabid <imabid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 17:28:30 by hbel-hou          #+#    #+#             */
/*   Updated: 2022/07/29 20:17:44 by imabid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Cub3d.h"

void	move_left(t_window *conf)
{
	if (conf->map[(int)((conf->player.py - (cos(conf->player.rotangle)
					* conf->player.movespeed)) / TILE_SIZE)][(int)((
			conf->player.px + (sin(conf->player.rotangle)
			* conf->player.movespeed)) / TILE_SIZE)] != '1')
	{
		conf->player.px += sin(
				conf->player.rotangle) * conf->player.movespeed;
		conf->player.py -= cos(
				conf->player.rotangle) * conf->player.movespeed;
	}
}

void	move_right(t_window *conf)
{
	if (conf->map[(int)((conf->player.py + (cos(conf->player.rotangle)
					* conf->player.movespeed)) / TILE_SIZE)][(int)((
			conf->player.px - (sin(conf->player.rotangle)
			* conf->player.movespeed)) / TILE_SIZE)] != '1')
	{
		conf->player.px -= sin(
				conf->player.rotangle) * conf->player.movespeed;
		conf->player.py += cos(
				conf->player.rotangle) * conf->player.movespeed;
	}
}

void	move_forward(t_window *conf)
{
	float	pdx;
	float	pdy;

	pdx = cos(conf->player.rotangle);
	pdy = sin(conf->player.rotangle);
	if (conf->map[(int)((conf->player.py + (pdy * conf->player.movespeed))
			/ TILE_SIZE)][(int)((conf->player.px
		+ (pdx * conf->player.movespeed)) / TILE_SIZE)] != '1')
	{
		conf->player.px += pdx * conf->player.movespeed;
		conf->player.py += pdy * conf->player.movespeed;
	}
}

void	move_backward(t_window *conf)
{
	float	pdx;
	float	pdy;

	pdx = -cos(conf->player.rotangle);
	pdy = -sin(conf->player.rotangle);
	if (conf->map[(int)((conf->player.py + (pdy
					* conf->player.movespeed)) / TILE_SIZE)][(int)(
		(conf->player.px + (pdx
		* conf->player.movespeed)) / TILE_SIZE)] != '1')
	{
		conf->player.px += pdx
			* conf->player.movespeed;
		conf->player.py += pdy
			* conf->player.movespeed;
	}
}

void	move_to(t_window *conf)
{
	if (conf->player.to_a == 1)
		move_left(conf);
	if (conf->player.to_d == 1)
		move_right(conf);
	if (conf->player.to_w == 1)
		move_forward(conf);
	if (conf->player.to_s == 1)
		move_backward(conf);
}
