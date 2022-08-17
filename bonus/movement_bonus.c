/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imabid <imabid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 11:48:42 by hbel-hou          #+#    #+#             */
/*   Updated: 2022/08/15 13:51:34 by imabid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3d_bonus.h"

void	move_left_bonus(t_window *conf)
{
	if (conf->map[(int)((conf->player.py - (cos(conf->player.rotangle)
					* conf->player.movespeed)) / TILE_SIZE)][(int)((
			conf->player.px + (sin(conf->player.rotangle)
			* conf->player.movespeed)) / TILE_SIZE)] != '1' &&
			conf->map[(int)((conf->player.py - (cos(conf->player.rotangle)
			* conf->player.movespeed)) / TILE_SIZE)][(int)((conf->player.px
			+ (sin(conf->player.rotangle) * conf->player.movespeed))
			/ TILE_SIZE)] != '2')
	{
		conf->player.px += sin(
				conf->player.rotangle) * conf->player.movespeed;
		conf->player.py -= cos(
				conf->player.rotangle) * conf->player.movespeed;
	}
}

void	move_right_bonus(t_window *conf)
{
	if (conf->map[(int)((conf->player.py + (cos(conf->player.rotangle)
					* conf->player.movespeed)) / TILE_SIZE)][(int)((
			conf->player.px - (sin(conf->player.rotangle)
			* conf->player.movespeed)) / TILE_SIZE)] != '1' &&
			conf->map[(int)((conf->player.py + (cos(conf->player.rotangle)
			* conf->player.movespeed)) / TILE_SIZE)][(int)((conf->player.px
			- (sin(conf->player.rotangle) * conf->player.movespeed))
			/ TILE_SIZE)] != '2')
	{
		conf->player.px -= sin(
				conf->player.rotangle) * conf->player.movespeed;
		conf->player.py += cos(
				conf->player.rotangle) * conf->player.movespeed;
	}
}

void	move_forward_bonus(t_window *conf)
{
	float	pdx;
	float	pdy;

	pdx = cos(conf->player.rotangle);
	pdy = sin(conf->player.rotangle);
	if (conf->map[(int)((conf->player.py)
			/ TILE_SIZE)][(int)((conf->player.px
			+ (pdx * conf->player.movespeed)) / TILE_SIZE)] != '1' &&
			conf->map[(int)(conf->player.py
			/ TILE_SIZE)][(int)((conf->player.px
			+ (pdx * conf->player.movespeed)) / TILE_SIZE)] != '2')
	{
		conf->player.px += pdx * conf->player.movespeed;
	}
	if (conf->map[(int)((conf->player.py + (pdy * conf->player.movespeed))
			/ TILE_SIZE)][(int)((conf->player.px) / TILE_SIZE)] != '1'
		&& conf->map[(int)((conf->player.py + (pdy * conf->player.movespeed))
		/ TILE_SIZE)][(int)((conf->player.px) / TILE_SIZE)] != '2')
		conf->player.py += pdy * conf->player.movespeed;
}

void	move_backward_bonus(t_window *conf)
{
	float	pdx;
	float	pdy;

	pdx = -cos(conf->player.rotangle);
	pdy = -sin(conf->player.rotangle);
	if (conf->map[(int)((conf->player.py + (pdy
					* conf->player.movespeed)) / TILE_SIZE)][(int)(
		(conf->player.px + (pdx
		* conf->player.movespeed)) / TILE_SIZE)] != '1' &&
		conf->map[(int)((conf->player.py + (pdy
		* conf->player.movespeed)) / TILE_SIZE)][(int)((conf->player.px
		+ (pdx * conf->player.movespeed))
		/ TILE_SIZE)] != '2')
	{
		conf->player.px += pdx
			* conf->player.movespeed;
		conf->player.py += pdy
			* conf->player.movespeed;
	}
}

void	move_to_bonus(t_window *conf)
{
	float	pdx;
	float	pdy;

	pdx = cos(conf->player.rotangle);
	pdy = sin(conf->player.rotangle);
	if (conf->player.to_a == 1)
		move_left_bonus(conf);
	if (conf->player.to_d == 1)
		move_right_bonus(conf);
	if (conf->player.to_w == 1)
		move_forward_bonus(conf);
	if (conf->player.to_s == 1)
		move_backward_bonus(conf);
	if (conf->player.to_space == 1)
		open_door(conf, pdx, pdy);
}
