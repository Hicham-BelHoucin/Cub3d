/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbel-hou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 10:55:31 by hbel-hou          #+#    #+#             */
/*   Updated: 2021/11/08 16:57:21 by hbel-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned int		i;
	const unsigned char	*s1i;
	const unsigned char	*s2i;

	i = 0;
	s1i = s1;
	s2i = s2;
	while (i < n)
	{
		if (s1i[i] != s2i[i])
			return (s1i[i] - s2i[i]);
		i++;
	}
	return (0);
}
