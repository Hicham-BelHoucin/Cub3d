/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ceilling_and_floor.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbel-hou <hbel-hou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 12:42:33 by hbel-hou          #+#    #+#             */
/*   Updated: 2022/08/17 17:47:48 by hbel-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Cub3d.h"

static void	draw_ceilling(int color, t_window *conf)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT / 2)
	{
		x = 0;
		while (x < WIDTH)
		{
			conf->addr[(y * WIDTH + x)] = color;
			x++;
		}
		y++;
	}
}

static void	draw_floor(int color, t_window *conf)
{
	int	y;
	int	x;

	y = HEIGHT / 2;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			conf->addr[(y * WIDTH + x)] = color;
			x++;
		}
		y++;
	}
}

void	draw_ceilling_or_floor(t_window *window, char *identifier)
{
	int	i;

	i = 0;
	while (i < 2)
	{
		if (!ft_strcmp(window->color[i].identifier, identifier)
			&& identifier[0] == 'F')
			draw_floor(window->color[i].color, window);
		if (!ft_strcmp(window->color[i].identifier, identifier)
			&& identifier[0] == 'C')
			draw_ceilling(window->color[i].color, window);
		i++;
	}
	return ;
}
