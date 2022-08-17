/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbel-hou <hbel-hou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 14:50:33 by hbel-hou          #+#    #+#             */
/*   Updated: 2022/07/28 18:32:03 by hbel-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Cub3d.h"

char	**list_to_char(t_list *list)
{
	char	**temp;
	int		i;

	i = 0;
	temp = (char **)malloc(sizeof(char *) * ft_lstsize(list) + 1);
	if (!temp)
		return (NULL);
	while (list)
	{
		temp[i] = list->content;
		i++;
		list = list->next;
	}
	temp[i] = NULL;
	return (temp);
}

size_t	ft_arr_length(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

int	get_color(int r, int g, int b)
{
	int	color;

	color = b;
	color = color | (g << 8);
	color = color | (r << 16);
	return (color);
}

int	check_color_content(char **temp, t_colors *tofill, char *str)
{
	int		j;
	int		end;
	int		colors[3];
	char	*dup;

	j = -1;
	end = ft_strcspn(str, " ");
	tofill->identifier = ft_substr(str, 0, end);
	if (ft_strcmp(tofill->identifier, "F")
		&& ft_strcmp(tofill->identifier, "C"))
		return (display("Invalid Identifier"));
	while (temp[++j])
	{
		dup = ft_strtrim(temp[j], " \n");
		if (ft_strspn(dup, "0123456789") != ft_strlen(dup))
			return (display("Colors Must Be composed of only Digits"));
		if (ft_atoi(dup) < 0 || ft_atoi(dup) > 255)
			return (display("Colors Must Be in Range [0 => 255]"));
		colors[j] = ft_atoi(dup);
		free(dup);
	}
	if (j != 3)
		return (display("Usage : Ex: [F 220,100,22 || C 220,100,22]"));
	tofill->color = get_color(colors[0], colors[1], colors[2]);
	return (0);
}

int	check_map_colors(t_list *colors, t_colors *tofill, char **temp)
{
	int			i;

	i = 0;
	if (ft_lstsize(colors) != 2)
		return (display("Usage : Ex: [F 220,100,22 || C 220,100,22]"));
	while (colors)
	{
		temp = ft_split((char *)colors->content + 2, ',');
		if (!temp)
			return (display("Split Error"));
		if (check_color_content(temp, tofill + i,
				(char *)colors->content) == -1)
			return (-1);
		ft_free_arr(temp);
		colors = colors->next;
		i++;
	}
	return (0);
}
