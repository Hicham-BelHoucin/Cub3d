/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbel-hou <hbel-hou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 11:58:56 by hbel-hou          #+#    #+#             */
/*   Updated: 2022/08/17 14:45:18 by hbel-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Cub3d.h"

int	parse_args(int fd)
{
	t_data		data;
	t_elements	*elements;
	t_colors	*colors;
	char		**temp;

	temp = NULL;
	colors = malloc(sizeof(t_colors) * 3);
	elements = malloc(sizeof(t_elements) * 4);
	if (!colors || !elements)
		return (display("Malloc Error"));
	data = ft_getmap(fd);
	if (check_map_elements(data.elements, &elements) == -1)
		return (-1);
	if (check_map_colors(data.colors, colors, temp) == -1)
		return (-1);
	temp = list_to_char(data.map);
	if (!temp || !(*temp))
		return (-1);
	if (check_map_content(temp, "01SEWN \n") == -1)
		return (-1);
	if (create_window(data, elements, colors) == -1)
		return (-1);
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
