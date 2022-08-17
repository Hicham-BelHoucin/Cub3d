/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbel-hou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 09:02:19 by hbel-hou          #+#    #+#             */
/*   Updated: 2021/11/07 11:09:41 by hbel-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t		j;
	char		*buffer;

	if (!s1 || !set)
		return (NULL);
	while (*s1 && ft_strchr(set, *s1) != 0)
		s1++;
	j = ft_strlen(s1);
	while (j && ft_strchr(set, s1[j]) != 0)
		j--;
	buffer = ft_substr((char *)s1, 0, j + 1);
	return (buffer);
}
