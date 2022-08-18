/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __tools.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbel-hou <hbel-hou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 14:35:07 by hbel-hou          #+#    #+#             */
/*   Updated: 2022/08/18 13:50:23 by hbel-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3d_bonus.h"

int	check_for_error_bonus(char **map, int i, int j)
{
	if (map[i][j + 1] != '1' && map[i][j + 1] != '0'
			&& !ft_strchr("SEWN2", map[i][j + 1]))
		return (print_error_pos(i, j, map[i][j]));
	if (!map[i][j + 1])
		return (print_error_pos(i, j, map[i][j]));
	if (map[i][j - 1] != '1' && map[i][j - 1] != '0'
		&& !ft_strchr("SEWN2", map[i][j - 1]))
		return (print_error_pos(i, j, map[i][j]));
	if (!map[i][j - 1])
		return (print_error_pos(i, j, map[i][j]));
	if (map[i + 1][j] != '1' && map[i + 1][j] != '0'
		&& !ft_strchr("SEWN2", map[i + 1][j]))
		return (print_error_pos(i, j, map[i][j]));
	if (!map[i + 1][j])
		return (print_error_pos(i, j, map[i][j]));
	if (map[i - 1][j] != '1' && map[i - 1][j] != '0'
		&& !ft_strchr("SEWN2", map[i - 1][j]))
		return (print_error_pos(i, j, map[i][j]));
	if (!map[i - 1][j])
		return (print_error_pos(i, j, map[i][j]));
	return (0);
}

int	check_door(char **map, int i, int j)
{
	if (map[i][j - 1] == '1' && map[i][j + 1] == '1')
		return (0);
	else if (map[i - 1][j] == '1' && map[i + 1][j] == '1')
		return (0);
	return (display("The door must be closed/surrounded by walls"));
}

int	check_valid_path_bonus(char **map, int i, int j)
{
	if (i == 0)
		return (0);
	if (map[i][j] == '0')
		if (check_for_error_bonus(map, i, j) == -1)
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
	if (ft_strchr("SEWN2", map[i][j]))
		if (check_for_error_bonus(map, i, j) == -1)
			return (-1);
	if (map[i][j] == '2')
		if (check_door(map, i, j) == -1)
			return (-1);
	return (0);
}

int	check_map_content_bonus(char **temp, char *charset)
{
	int		i;
	int		j;

	i = 0;
	if (ft_strspn(temp[i], "1 \n") != ft_strlen(temp[i]))
		return (display("The map must be closed/surrounded by walls"));
	while (temp[i + 1])
	{
		if (ft_strspn(temp[i], charset) != ft_strlen(temp[i]))
			return (display("Map must Be Composed Of Only '01SEWN'"));
		j = ft_strspn(temp[i], " ");
		if (temp[i][j] != '1')
			return (print_error_pos(i, j, temp[i][j]));
		j = 0;
		while (temp[i][j])
		{
			if (check_valid_path_bonus(temp, i, j) == -1)
				return (-1);
			j++;
		}
		i++;
	}
	if (ft_strspn(temp[i], "1 \n") != ft_strlen(temp[i]))
		return (display("The map must be closed/surrounded by walls"));
	return (0);
}

char	**ft_cpy_arr(char **str)
{
	char	**new_map;
	int		i;

	i = 0;
	while (str[i])
		i++;
	new_map = malloc(sizeof(char *) * i + 1);
	if (!new_map)
		exit(display("Error fatal ! : Malloc Error"));
	i = 0;
	while (str[i])
	{
		new_map[i] = ft_strdup(str[i]);
		i++;
	}
	new_map[i] = NULL;
	return (new_map);
}
