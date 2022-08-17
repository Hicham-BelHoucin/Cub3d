/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handlers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imabid <imabid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 14:36:01 by hbel-hou          #+#    #+#             */
/*   Updated: 2022/08/15 13:42:27 by imabid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3d_bonus.h"

void	push_gun_to_window(int key, t_window *conf)
{
	t_texture	gun;

	if (key == F)
	{
		conf->ammo--;
		if (conf->ammo >= 0)
		{
			gun = load_img("./asset/gun2222.xpm", conf->mlx);
			mlx_put_image_to_window(conf->mlx, conf->win, gun.img,
				(WIDTH / 2) - 200, HEIGHT - 360);
		}
	}
	else if (key == R)
	{
		conf->r = 1;
		conf->ammo = 5;
	}
	return ;
}

int	player_move_bonus(int key, t_window *conf)
{
	if (key == ESC)
		exit(0);
	else if (key == W)
		conf->player.to_w = 1;
	else if (key == D)
		conf->player.to_d = 1;
	else if (key == S)
		conf->player.to_s = 1;
	else if (key == A)
		conf->player.to_a = 1;
	else if (key == TOFORWARD)
		conf->player.to_forward = 1;
	else if (key == TOBACK)
		conf->player.to_back = 1;
	else if (key == SPACE)
		conf->player.to_space = 1;
	else if (key == F || key == R)
		push_gun_to_window(key, conf);
	return (0);
}

int	keyrealeased_bonus(int key, t_window *conf)
{
	if (key == ESC)
		exit(0);
	else if (key == W)
		conf->player.to_w = 0;
	else if (key == D)
		conf->player.to_d = 0;
	else if (key == S)
		conf->player.to_s = 0;
	else if (key == A)
		conf->player.to_a = 0;
	else if (key == TOFORWARD)
		conf->player.to_forward = 0;
	else if (key == TOBACK)
		conf->player.to_back = 0;
	else if (key == SPACE)
		conf->player.to_space = 0;
	else if (key == R)
		conf->r = 0;
	return (0);
}

int	mouse_hook(int x, int y, t_window *conf)
{
	static int	old_x;

	(void)y;
	if (x <= WIDTH && x >= 0 && x < old_x)
		conf->player.rotangle -= 2.5 * (PI / 180);
	if (x >= 0 && x <= WIDTH && x > old_x)
		conf->player.rotangle += 2.5 * (PI / 180);
	old_x = x;
	if (!(x >= 0 && x <= WIDTH))
		old_x = WIDTH / 2;
	return (0);
}
