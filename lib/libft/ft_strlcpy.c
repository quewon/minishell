/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 17:06:18 by qchin             #+#    #+#             */
/*   Updated: 2025/11/16 08:04:19 by qchin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t dsize)
{
	size_t	i;

	i = 0;
	while (i + 1 < dsize && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	if (dsize > 0)
		dest[i] = '\0';
	return (ft_strlen(src));
}
