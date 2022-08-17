/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strspn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbel-hou <hbel-hou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 08:41:36 by hbel-hou          #+#    #+#             */
/*   Updated: 2022/06/05 12:14:51 by hbel-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strspn(const char *str, const char *charset)
{
	int	i;

	i = 0;
	if (str == NULL || charset == NULL)
		return (i);
	while (str[i] && ft_strchr(charset, str[i]))
		i++;
	return (i);
}
