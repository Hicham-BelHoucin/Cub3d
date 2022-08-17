/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbel-hou <hbel-hou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 14:45:46 by hbel-hou          #+#    #+#             */
/*   Updated: 2022/06/30 18:38:09 by hbel-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Cub3d.h"

t_texture	load_img(char *path, void *mlx)
{
	t_texture	temp;

	temp.x = 0;
	temp.y = 0;
	temp.width = 64;
	temp.height = 64;
	temp.img = mlx_xpm_file_to_image(mlx, path, &temp.width, &temp.height);
	if (!temp.img)
		exit(printf("mlx Error : mlx_xpm_file_to_image !\n"));
	temp.addr = (int *)mlx_get_data_addr(temp.img,
			&temp.bits_per_pixel, &temp.size_line, &temp.endian);
	if (!temp.addr)
		exit(printf("mlx Error : mlx_get_data_addr!\n"));
	return (temp);
}

int	check_texture_name(t_elements **tofill, int i)
{
	if (ft_strcmp((*tofill)[i].identifier, SOUTHTEXTURE)
		&& ft_strcmp((*tofill)[i].identifier, NORTHTEXTURE)
		&& ft_strcmp((*tofill)[i].identifier, WESTTEXTURE)
		&& ft_strcmp((*tofill)[i].identifier, EASTTEXTURE))
		return (display("Invalid Identifier"));
	return (0);
}

int	display(char *error)
{
	printf("%sError\n%s\n", RED, error);
	return (-1);
}

void	print_error(char *str, t_data data)
{
	if (str)
		printf("%sError: %s\n", RED, str);
	if (data.colors)
		clear_list(data.colors);
	if (data.map)
		clear_list(data.map);
	if (data.elements)
		clear_list(data.elements);
	exit(EXIT_FAILURE);
}

int	print_error_pos(int row, int column, char c)
{
	printf("%sError\nrow : [%d] colmn : [%d] char : [%c]\n", RED, row, column, c);
	return (-1);
}
