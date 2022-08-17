/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkMap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbel-hou <hbel-hou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 14:23:22 by hbel-hou          #+#    #+#             */
/*   Updated: 2022/08/17 14:46:26 by hbel-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Cub3d.h"

int	check_player_existence(char **str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (ft_strchr("SEWN", str[i][j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_duplicate_player(char **temp)
{
	char	*pos;
	int		i;
	int		j;

	i = 0;
	pos = NULL;
	if (!check_player_existence(temp))
		exit(display("missing player In Map"));
	while (temp[i])
	{
		j = 0;
		while (temp[i][j])
		{
			if (pos && (temp[i][j] == 'N' || temp[i][j] == 'E'
				|| temp[i][j] == 'W' || temp[i][j] == 'S'))
				return (display("Duplicate player In Map"));
			if (ft_strchr("NWES", temp[i][j]))
				pos = ft_strchr(temp[i], temp[i][j]);
			j++;
		}
		i++;
	}
	free(temp);
	return (0);
}

int	check_map_content(char	**temp, char *charset)
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
			if (check_valid_path(temp, i, j) == -1)
				return (-1);
			j++;
		}
		i++;
	}
	if (ft_strspn(temp[i], "1 \n") != ft_strlen(temp[i]))
		return (display("The map must be closed/surrounded by walls"));
	return (0);
}

void	ft_free_arr(char **buffer)
{
	int	i;

	i = 0;
	while (buffer[i])
	{
		free(buffer[i]);
		i++;
	}
	free(buffer);
}
