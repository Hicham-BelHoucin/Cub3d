/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbel-hou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 10:42:55 by hbel-hou          #+#    #+#             */
/*   Updated: 2021/11/08 16:57:09 by hbel-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	const unsigned char	*src;
	int					i;

	src = str;
	i = 0;
	while (n != 0)
	{
		if (src[i] == (unsigned char)c)
			return ((unsigned char *)&src[i]);
		i++;
		n--;
	}
	return (0);
}
