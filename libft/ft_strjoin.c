/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbel-hou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 08:48:09 by hbel-hou          #+#    #+#             */
/*   Updated: 2021/11/07 11:16:53 by hbel-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	int		k;
	int		m;
	char	*buffer;

	m = 0;
	k = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	else
	{
		j = ft_strlen(s1);
		i = ft_strlen(s2);
		buffer = malloc(sizeof(char) * i + j + 1);
		if (buffer == NULL)
			return (NULL);
		while (s1[k])
			buffer[m++] = s1[k++];
		k = 0;
		while (s2[k])
			buffer[m++] = s2[k++];
		buffer[m] = '\0';
		return (buffer);
	}
}
