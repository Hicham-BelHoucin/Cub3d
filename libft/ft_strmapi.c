/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbel-hou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 18:32:41 by hbel-hou          #+#    #+#             */
/*   Updated: 2021/11/10 18:32:46 by hbel-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strmapi(char const *str, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*buffer;

	i = 0;
	if (str == NULL || f == NULL)
		return (NULL);
	buffer = malloc(sizeof(char) * ft_strlen(str) + 1);
	if (buffer == NULL)
		return (NULL);
	while (str[i])
	{
		buffer[i] = f(i, str[i]);
		i++;
	}
	buffer[i] = '\0';
	return (buffer);
}
