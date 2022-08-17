/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbel-hou <hbel-hou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 17:18:15 by hbel-hou          #+#    #+#             */
/*   Updated: 2022/08/15 09:58:42 by hbel-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Cub3d.h"

int	main_loop(t_window *window)
{
	mlx_clear_window(window->mlx, window->win);
	rendering_walls(window);
	mlx_hook(window->win, 2, 1L << 0, player_move, window);
	mlx_hook(window->win, 17, 0, close_win, window);
	mlx_hook(window->win, 3, 1L << 1, keyrealeased, window);
	mlx_put_image_to_window(window->mlx, window->win, window->img, 0, 0);
	return (0);
}

int	create_window(t_data data, t_elements *elm, t_colors *col)
{
	t_window	window;

	window.mlx = mlx_init();
	window.win = mlx_new_window(window.mlx, WIDTH, HEIGHT, "Cub3d");
	window.img = mlx_new_image(window.mlx, WIDTH, HEIGHT);
	window.addr = (int *)mlx_get_data_addr(window.img, &window.bits,
			&window.size, &window.endian);
	if (!window.addr)
		return (display("Error in mlxGetDataAddr"));
	window.elem = elm;
	window.color = col;
	window.map = list_to_char(data.map);
	if (!window.map)
		return (display("Malloc error"));
	window.old_map = NULL;
	get_filled_map(window.map);
	init_all(&window);
	cast_rays_helper(&window);
	mlx_loop_hook(window.mlx, &main_loop, &window);
	mlx_loop(window.mlx);
	return (0);
}
