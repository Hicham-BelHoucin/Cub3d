/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbel-hou <hbel-hou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 12:47:43 by hbel-hou          #+#    #+#             */
/*   Updated: 2022/07/29 11:39:07 by hbel-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Cub3d.h"

int	player_move(int key, t_window *conf)
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
	return (0);
}

int	keyrealeased(int key, t_window *conf)
{
	if (key == ESC)
	{
		clear(conf);
		exit(EXIT_SUCCESS);
	}
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
	return (0);
}

int	close_win(t_window *conf)
{
	clear(conf);
	exit(EXIT_SUCCESS);
}

void	rotate(t_window *conf)
{
	conf->player.rotangle = normalize_ang(conf->player.rotangle);
	if (conf->player.to_forward == 1)
		conf->player.rotangle -= conf->player.rotspeed;
	if (conf->player.to_back == 1)
		conf->player.rotangle += conf->player.rotspeed;
}
