/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkElements.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbel-hou <hbel-hou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 14:48:39 by hbel-hou          #+#    #+#             */
/*   Updated: 2022/08/18 13:43:35 by hbel-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Cub3d.h"

int	check_for_error(char **map, int i, int j)
{
	if (map[i][j + 1] != '1' && map[i][j + 1] != '0'
			&& !ft_strchr("SEWN", map[i][j + 1]))
		return (print_error_pos(i, j, map[i][j]));
	if (!map[i][j + 1])
		return (print_error_pos(i, j, map[i][j]));
	if (map[i][j - 1] != '1' && map[i][j - 1] != '0'
		&& !ft_strchr("SEWN", map[i][j - 1]))
		return (print_error_pos(i, j, map[i][j]));
	if (!map[i][j - 1])
		return (print_error_pos(i, j, map[i][j]));
	if (map[i + 1][j] != '1' && map[i + 1][j] != '0'
		&& !ft_strchr("SEWN", map[i + 1][j]))
		return (print_error_pos(i, j, map[i][j]));
	if (!map[i + 1][j])
		return (print_error_pos(i, j, map[i][j]));
	if (map[i - 1][j] != '1' && map[i - 1][j] != '0'
		&& !ft_strchr("SEWN", map[i - 1][j]))
		return (print_error_pos(i, j, map[i][j]));
	if (!map[i - 1][j])
		return (print_error_pos(i, j, map[i][j]));
	return (0);
}

int	check_valid_path(char **map, int i, int j)
{
	if (i == 0)
		return (0);
	if (map[i][j] == '0')
		if (check_for_error(map, i, j) == -1)
			return (-1);
	if (map[i][j] == ' ')
	{
		if (j - 1 == -1)
			return (0);
		if (map[i][j + 1] != '1' && map[i][j + 1] != ' '
			&& !ft_strchr("SEWN", map[i][j + 1]))
			return (print_error_pos(i, j, map[i][j]));
		if (map[i][j - 1] != '1' && map[i][j - 1] != ' '
			&& !ft_strchr("SEWN", map[i][j - 1]))
			return (print_error_pos(i, j, map[i][j]));
	}
	if (ft_strchr("SEWN", map[i][j]))
		if (check_for_error(map, i, j) == -1)
			return (-1);
	return (0);
}

int	check_file_existence(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (-1);
	close(fd);
	return (0);
}

static int	check_duplicate(char *identifier, t_elements *tocompare, int length)
{
	int	i;

	i = length;
	while (length >= 0)
	{
		if (!ft_strcmp(tocompare[length].identifier, identifier))
			return (display("duplicate texture !"));
		length--;
	}
	if (check_file_existence(tocompare[i + 1].path) == -1)
		return (display("File Does Not Exist"));
	return (0);
}

int	check_map_elements(t_list *elements, t_elements **tofill)
{
	int		start;
	char	*str;
	int		i;

	i = -1;
	if (ft_lstsize(elements) != 4)
		return (display("Invalid Number Of Textures"));
	while (elements)
	{
		str = (char *)elements->content;
		start = ft_strcspn(str, " ");
		(*tofill)[++i].identifier = ft_substr(str, 0, start);
		if (!(*tofill)[i].identifier || !(*tofill)[i].identifier[0]
				|| !ft_strchr("./abcdefghijklmnopqrstuvwxyz", str[start + 1]))
			return (display("Invalid Identifier"));
		if (check_texture_name(tofill, i) == -1)
			return (-1);
		start = ft_strcspn(str, "./abcdefghijklmnopqrstuvwxyz");
		(*tofill)[i].path = ft_strchr(str, str[start]);
		if (check_duplicate((*tofill)[i].identifier, *tofill, i - 1) == -1)
			return (-1);
		elements = elements->next;
	}
	return (0);
}
