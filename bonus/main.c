/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbel-hou <hbel-hou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 11:58:56 by hbel-hou          #+#    #+#             */
/*   Updated: 2022/08/17 17:49:27 by hbel-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3d_bonus.h"

int	main_loop_bonus(t_window *window)
{
	mlx_clear_window(window->mlx, window->win);
	draw_ceilling_or_floor(window, "C");
	draw_ceilling_or_floor(window, "F");
	rendering_walls_bonus(window);
	mlx_hook(window->win, 2, 1L << 0, player_move_bonus, window);
	mlx_hook(window->win, 17, 0, close_win, window);
	mlx_hook(window->win, 3, 1L << 1, keyrealeased_bonus, window);
	mlx_hook(window->win, 6, 0, mouse_hook, window);
	return (0);
}

void	create_window_bonus(t_data data, t_elements *elm, t_colors *col)
{
	t_window	window;

	window.mlx = mlx_init();
	window.win = mlx_new_window(window.mlx, WIDTH, HEIGHT, "Cub3d");
	window.img = mlx_new_image(window.mlx, WIDTH, HEIGHT);
	window.addr = (int *)mlx_get_data_addr(window.img, &window.bits,
			&window.size, &window.endian);
	window.elem = elm;
	window.color = col;
	window.door = load_img("./asset/door.xpm", window.mlx);
	window.map = list_to_char(data.map);
	window.old_map = ft_cpy_arr(window.map);
	get_filled_map(window.map);
	init_all(&window);
	window.ammo = 5;
	cast_rays_helper(&window);
	mlx_loop_hook(window.mlx, &main_loop_bonus, &window);
	mlx_loop(window.mlx);
}

int	parse_args(int fd)
{
	t_data		data;
	t_elements	*elements;
	t_colors	*colors;
	char		**temp;

	temp = NULL;
	colors = malloc(sizeof(t_colors) * 3);
	elements = malloc(sizeof(t_elements) * 4);
	if (!elements || !colors)
		return (display("Malloc error"));
	data = ft_getmap(fd);
	if (check_map_elements(data.elements, &elements) == -1)
		return (-1);
	if (check_map_colors(data.colors, colors, temp) == -1)
		return (-1);
	temp = list_to_char(data.map);
	if (check_map_content_bonus(temp, "012SEWN \n") == -1)
		return (-1);
	create_window_bonus(data, elements, colors);
	return (0);
}

int	main(int ac, char *av[])
{
	int			fd;

	if (ac != 2 || ft_strcmp(av[1] + (ft_strlen(av[1]) - 4), ".cub"))
		return (display("Usage: ./Cub3d maps/map.cub"));
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (display("File Does Not Exist"));
	if (parse_args(fd) == -1)
		return (EXIT_FAILURE);
	return (0);
}
