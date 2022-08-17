/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbel-hou <hbel-hou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 18:45:43 by hbel-hou          #+#    #+#             */
/*   Updated: 2022/06/21 09:09:18 by hbel-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	size_t		i;
	size_t		j;
	char		k;

	i = 0;
	j = ft_strlen(str);
	k = (char)c;
	while (i <= j)
	{
		if (str[i] == k)
			return ((char *)&str[i]);
		i++;
	}
	return (NULL);
}
