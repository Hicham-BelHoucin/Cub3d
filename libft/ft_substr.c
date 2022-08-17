/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbel-hou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 08:54:31 by hbel-hou          #+#    #+#             */
/*   Updated: 2021/11/07 11:07:57 by hbel-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*buffer;
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	if (s == NULL)
		return (NULL);
	if (len > ft_strlen(s))
		buffer = malloc(sizeof(*s) * (ft_strlen(s) + 1));
	else
		buffer = malloc(sizeof(*s) * (len + 1));
	if (buffer == NULL)
		return (NULL);
	while (s[i])
	{
		if (i >= start && j < len)
			buffer[j++] = s[i];
		i++;
	}
	buffer[j] = '\0';
	return (buffer);
}
