/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getNextLine.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbel-hou <hbel-hou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 09:10:01 by hbel-hou          #+#    #+#             */
/*   Updated: 2022/07/26 12:54:13 by hbel-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Cub3d.h"

static char	*free_and_return(char *buff, char *rest)
{
	if (buff != NULL)
		free(buff);
	if (rest != NULL)
		free(rest);
	return (NULL);
}

char	*get_next_line(int fd)
{
	char	*buff;
	char	*rest;
	char	*temp;
	int		i;

	i = 9;
	buff = ft_strdup("");
	rest = ft_strdup("");
	while (i != 0 && buff[0] != '\n')
	{
		i = read(fd, buff, 1);
		if (i == -1 || buff == NULL)
			return (free_and_return(buff, rest));
		buff[i] = '\0';
		temp = ft_strdup(rest);
		free(rest);
		rest = ft_strjoin(temp, buff);
		free(temp);
	}
	free(buff);
	if (!rest[0])
		return (free_and_return(NULL, rest));
	return (rest);
}
