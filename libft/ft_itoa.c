/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbel-hou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 13:33:43 by hbel-hou          #+#    #+#             */
/*   Updated: 2021/11/08 16:51:26 by hbel-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static char	*ft_array(char *buffer, unsigned int i, long int j)
{
	while (i > 0)
	{
		buffer[j] = 48 + (i % 10);
		i = i / 10;
		j--;
	}
	return (buffer);
}

static long int	ft_len(int n)
{
	int	i;

	i = 0;
	if (n <= 0)
		i = 1;
	while (n != 0)
	{
		i++;
		n = n / 10;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char			*buffer;
	int				i;
	unsigned int	j;

	i = ft_len(n);
	buffer = (char *)malloc(sizeof(char) * (i + 1));
	if (buffer == NULL)
		return (NULL);
	buffer[i--] = '\0';
	if (n == 0)
		buffer[0] = '0';
	if (n < 0)
	{
		j = n * -1;
		buffer[0] = '-';
	}
	else
		j = n;
	buffer = ft_array(buffer, j, i);
	return (buffer);
}
