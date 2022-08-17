/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbel-hou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 17:34:52 by hbel-hou          #+#    #+#             */
/*   Updated: 2021/11/10 18:27:09 by hbel-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	size_t				i;
	unsigned char		*dst;
	const unsigned char	*sc;

	dst = (unsigned char *)dest;
	sc = (unsigned char *)src;
	i = 0;
	if (dst == NULL && sc == NULL)
		return (NULL);
	if (sc < dst)
		while (len--)
			dst[len] = sc[len];
	else
	{
		while (len--)
		{
			dst[i] = sc[i];
			i++;
		}
	}
	return (dst);
}
