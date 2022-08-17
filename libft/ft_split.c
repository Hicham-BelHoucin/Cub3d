/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbel-hou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 11:07:59 by hbel-hou          #+#    #+#             */
/*   Updated: 2021/11/08 17:04:49 by hbel-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(char const *str, char c)
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != c && (str[i + 1] == c || str[i + 1] == '\0'))
			j++;
		i++;
	}
	return (j);
}

static int	count_len(char const *str, char c)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (str[i] != c && str[i] != '\0')
	{
		i++;
		len++;
	}
	return (len);
}

static void	ft_free(char **buffer)
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

static char	**ft_fill(char const *str, int w, char c, char **buffer)
{
	int		i;
	int		j;
	int		len;

	i = 0;
	while (i < w)
	{
		while (*str == c)
			str++;
		len = count_len(str, c);
		buffer[i] = (char *)malloc(sizeof(char) * (len + 1));
		if (buffer[i] == NULL)
		{
			ft_free(buffer);
			return (NULL);
		}
		j = 0;
		while (j < len)
			buffer[i][j++] = *str++;
		buffer[i][j] = '\0';
		i++;
	}
	buffer[i] = NULL;
	return (buffer);
}

char	**ft_split(char	const *str, char c)
{
	char	**buffer;
	int		i;

	if (str == NULL)
		return (NULL);
	i = ft_count(str, c);
	buffer = (char **)malloc(sizeof(char *) * (i + 1));
	if (buffer == NULL)
		return (NULL);
	buffer = ft_fill(str, i, c, buffer);
	return (buffer);
}
