/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbel-hou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 16:58:35 by hbel-hou          #+#    #+#             */
/*   Updated: 2021/11/08 16:58:46 by hbel-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void *str, int c, size_t n )
{
	size_t			i;
	unsigned char	*src;
	char			x;

	i = 0;
	x = (char)c;
	src = (unsigned char *)str;
	while (i < n)
	{
		src[i] = x;
		i++;
	}
	return (src);
}
