/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getMap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbel-hou <hbel-hou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 11:52:21 by hbel-hou          #+#    #+#             */
/*   Updated: 2022/08/15 09:55:43 by hbel-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Cub3d.h"

static char	*remove_char(char *str)
{
	char	*temp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == ' ')
		{
			j = i;
			i = ft_strspn(str + i, " ");
			i += j - 1;
			while (str[i] && str[i] != '\n')
				str[j++] = str[i++];
			str[j] = '\0';
			temp = ft_strdup(str);
			return (temp);
		}
		i++;
	}
	return (str);
}

void	clear_list(t_list *list)
{
	t_list	*temp;

	while (list)
	{
		temp = list;
		free(list->content);
		list = list->next;
		free(temp);
	}
}

int	length(char *str)
{
	int		i;

	i = ft_strlen(str) - 1;
	if (str[i] == '\n')
		i--;
	while (str[i] && str[i] != '1' && str[i] != '0' && str[i] == ' ')
		i--;
	return (++i);
}

char	*push_to_list(char *str, int i, char *type, t_data *data)
{
	if (ft_strchr("NSWE", str[i]))
	{
		type = "element";
		ft_lstadd_back(&data->elements, ft_lstnew(remove_char(str + i)));
	}
	else if (ft_strchr("FC", str[i]))
	{
		type = "element";
		ft_lstadd_back(&data->colors, ft_lstnew(remove_char(str + i)));
	}
	else if (ft_strchr("01SEWN ", str[i]))
	{
		if (!ft_strcmp(type, "element") && data->map)
			print_error("Error in Order Of elements and map", *data);
		type = "map";
		ft_lstadd_back(&data->map, ft_lstnew(ft_substr(str, 0, length(str))));
	}
	else if (ft_strspn(str, " \n") == ft_strlen(str) && ft_strcmp(str, "\n"))
		print_error("misconfiguration is encountered in the file", *data);
	else if (str[i] != '\n' || (!ft_strcmp(type, "map") && str[i] == '\n'))
		print_error("misconfiguration is encountered in the file", *data);
	return (type);
}

t_data	ft_getmap(int fd)
{
	t_data	data;
	char	*str;
	char	*type;
	char	*old_line;

	data = (t_data){};
	old_line = ft_strdup("");
	while (1337)
	{
		str = get_next_line(fd);
		if (!str && ft_strchr(old_line, '\n'))
			print_error("misconfiguration is encountered in the file", data);
		if (str == NULL)
			break ;
		free(old_line);
		old_line = ft_strdup(str);
		type = push_to_list(str, ft_strspn(str, " "), type, &data);
		free(str);
	}
	free(old_line);
	if (check_duplicate_player(list_to_char(data.map)) == -1)
		print_error(NULL, data);
	return (data);
}
