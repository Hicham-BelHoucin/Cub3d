/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbel-hou <hbel-hou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 17:30:43 by hbel-hou          #+#    #+#             */
/*   Updated: 2022/08/17 17:46:09 by hbel-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Cub3d_bonus.h"

int	find_tex(t_elements *elm, char *identifier)
{
	int		i;

	i = -1;
	while (++i < 4)
	{
		if (!ft_strcmp(elm[i].identifier, identifier))
			return (i);
	}
	return (0);
}

void	texture_facing(t_window *conf)
{
	if (!conf->wall.hitver[conf->wall.drawstartx]
		&& conf->wall.faceup[conf->wall.drawstartx])
		conf->txtnbr = find_tex(conf->elem, "NO");
	if (!conf->wall.hitver[conf->wall.drawstartx]
		&& conf->wall.facedown[conf->wall.drawstartx])
		conf->txtnbr = find_tex(conf->elem, "SO");
	if (conf->wall.hitver[conf->wall.drawstartx]
		&& conf->wall.faceleft[conf->wall.drawstartx])
		conf->txtnbr = find_tex(conf->elem, "WE");
	if (conf->wall.hitver[conf->wall.drawstartx]
		&& conf->wall.faceright[conf->wall.drawstartx])
		conf->txtnbr = find_tex(conf->elem, "EA");
}

void	draw_wall(t_window *conf)
{
	int	offsety;
	int	offsetx;
	int	y;
	int	color;
	int	dftop;

	if (conf->wall.hitver[conf->wall.drawstartx])
		offsetx = (int)conf->wall.wy[conf->wall.drawstartx] % TILE_SIZE;
	else
		offsetx = (int)conf->wall.wx[conf->wall.drawstartx] % TILE_SIZE;
	y = conf->wall.topwall;
	texture_facing(conf);
	while (y < conf->wall.bottomwall)
	{
		dftop = y + (conf->wall.wallstripheight / 2) - (HEIGHT / 2);
		offsety = (dftop) * ((float)TEX_HEIGHT / conf->wall.wallstripheight);
		color = conf->elem[conf->txtnbr]
			.texture.addr[(offsety * TEX_HEIGHT) + offsetx];
		conf->addr[(y * WIDTH
				+ (conf->wall.drawstartx))] = color;
		y++;
	}
}

void	render3d(t_window *conf)
{
	conf->wall.playerwalldist = (WIDTH / 2) / tan(FOV / 2);
	conf->wall.wallstripheight = 1;
	conf->wall.drawstartx = 0;
	while (conf->wall.drawstartx < conf->ray.num_rays)
	{
		conf->wall.corrwall = conf->wall.line_distance[conf->wall.drawstartx]
			* cos(conf->ray.rayangle[conf->wall.drawstartx]
				- conf->player.rotangle);
		conf->wall.wallstripheight = (TILE_SIZE / conf->wall.corrwall)
			* conf->wall.playerwalldist;
		conf->wall.topwall = (HEIGHT / 2)
			- (conf->wall.wallstripheight / 2);
		conf->wall.bottomwall = (HEIGHT / 2)
			+ (conf->wall.wallstripheight / 2);
		conf->wall.topwall = int_ternary(conf->wall.topwall < 0,
				0, conf->wall.topwall);
		conf->wall.bottomwall = int_ternary(conf->wall.bottomwall > HEIGHT,
				HEIGHT, conf->wall.bottomwall);
		draw_wall(conf);
		conf->wall.drawstartx++;
	}
}

void	rendering_walls(t_window *window)
{
	cast_rays(window);
	draw_ceilling_or_floor(window, "C");
	draw_ceilling_or_floor(window, "F");
	render3d(window);
	move_to(window);
	rotate(window);
	mlx_put_image_to_window(window->mlx, window->win, window->img, 0, 0);
}
