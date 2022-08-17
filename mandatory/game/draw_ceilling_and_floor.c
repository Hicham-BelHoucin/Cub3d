/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ceilling_and_floor.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbel-hou <hbel-hou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 12:42:33 by hbel-hou          #+#    #+#             */
/*   Updated: 2022/08/05 13:31:21 by hbel-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Cub3d.h"

static void	draw_ceilling(int color, t_window *conf)
{
	int	x;

	x = 0;
	while (x < conf->wall.topwall)
	{
		conf->addr[(x * WIDTH + conf->wall.drawstartx)] = color;
		x++;
	}
}

static void	draw_floor(int color, t_window *conf)
{
	int	j;

	j = conf->wall.bottomwall;
	while (j < HEIGHT)
	{
		conf->addr[(j * WIDTH + conf->wall.drawstartx)] = color;
		j++;
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
