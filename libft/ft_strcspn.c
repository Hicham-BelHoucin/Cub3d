/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbel-hou <hbel-hou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 08:44:57 by hbel-hou          #+#    #+#             */
/*   Updated: 2022/06/05 12:12:15 by hbel-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strcspn(const char *str, const char *charset)
{
	int	i;

	i = 0;
	if (!str || !charset)
		return (i);
	while (str[i] && !ft_strchr(charset, str[i]))
		i++;
	return (i);
}
