/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbel-hou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 13:41:09 by hbel-hou          #+#    #+#             */
/*   Updated: 2021/11/07 11:15:38 by hbel-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	char	*str;
	size_t	dstlen;
	size_t	res;
	size_t	srclen;
	size_t	i;

	str = (char *)src;
	dstlen = ft_strlen(dst);
	srclen = ft_strlen(str);
	res = 0;
	i = 0;
	if (dstsize > dstlen)
		res = srclen + dstlen;
	else
		res = srclen + dstsize;
	while (str[i] && (dstlen + 1) < dstsize)
	{
		dst[dstlen] = str[i];
		dstlen++;
		i++;
	}
	dst[dstlen] = '\0';
	return (res);
}
