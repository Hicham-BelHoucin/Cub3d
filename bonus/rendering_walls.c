/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_walls.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbel-hou <hbel-hou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 14:45:35 by hbel-hou          #+#    #+#             */
/*   Updated: 2022/08/17 17:48:38 by hbel-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3d_bonus.h"

void	draw_wall_bonus(t_window *conf)
{
	int	offsety;
	int	offsetx;
	int	y;
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
		put_pixle(conf, y, offsetx, offsety);
		y++;
	}
}

void	render3d_bonus(t_window *conf)
{
	conf->wall.drawstartx = 0;
	while (conf->wall.drawstartx < conf->ray.num_rays)
	{
		conf->wall.playerwalldist = (WIDTH / 2) / tan(FOV / 2);
		conf->wall.corrwall = conf->wall.line_distance[conf->wall.drawstartx]
			* cos(conf->ray.rayangle[conf->wall.drawstartx]
				- conf->player.rotangle);
		conf->wall.wallstripheight = (int)((TILE_SIZE / conf->wall.corrwall)
				* conf->wall.playerwalldist);
		conf->wall.topwall = (HEIGHT / 2)
			- (conf->wall.wallstripheight / 2);
		conf->wall.bottomwall = (HEIGHT / 2)
			+ (conf->wall.wallstripheight / 2);
		conf->wall.topwall = int_ternary(conf->wall.topwall < 0,
				0, conf->wall.topwall);
		conf->wall.bottomwall = int_ternary(conf->wall.bottomwall > HEIGHT,
				HEIGHT, conf->wall.bottomwall);
		draw_wall_bonus(conf);
		conf->wall.drawstartx++;
	}
}

void	rendering_walls_bonus(t_window *window)
{
	t_texture	gun;
	t_texture	_ammo;
	int			ammo;

	gun = load_img("./asset/gun111.xpm", window->mlx);
	_ammo = load_img("./asset/ammo.xpm", window->mlx);
	cast_rays_bonus(window);
	render3d_bonus(window);
	mapp_print(window);
	player_print(window);
	move_to_bonus(window);
	rotate(window);
	mlx_put_image_to_window(window->mlx, window->win, window->img, 0, 0);
	if (window->r == 0 && window->ammo > 0)
		mlx_put_image_to_window(window->mlx, window->win, gun.img,
			(WIDTH / 2) - 200, (HEIGHT - 360));
	gun = load_img("asset/knife.xpm", window->mlx);
	if (window->ammo <= 0)
		mlx_put_image_to_window(window->mlx, window->win, gun.img,
			(WIDTH / 2) - 250, HEIGHT - 280);
	ammo = window->ammo;
	while (window->r == 0 && ammo-- > 0)
		mlx_put_image_to_window(window->mlx, window->win, _ammo.img,
			(ammo * 32), HEIGHT - 70);
	try_to_close_door(window);
}
