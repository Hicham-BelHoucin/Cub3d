/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbel-hou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 16:17:37 by hbel-hou          #+#    #+#             */
/*   Updated: 2021/11/08 16:49:51 by hbel-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*arr;
	char	*arr1;
	int		i;

	i = 0;
	arr = malloc(count * size);
	if (arr == NULL)
		return (NULL);
	arr1 = arr;
	ft_bzero(arr1, count * size);
	return (arr);
}
