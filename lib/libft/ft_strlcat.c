/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 00:33:27 by qchin             #+#    #+#             */
/*   Updated: 2025/11/16 17:12:02 by qchin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	min(size_t a, size_t b)
{
	if (a < b)
		return (a);
	return (b);
}

size_t	ft_strlcat(char *dest, const char *restrict src, size_t dsize)
{
	size_t	len;
	size_t	i;

	len = ft_strlen(dest);
	i = 0;
	while (len + i + 1 < dsize && src[i])
	{
		dest[len + i] = src[i];
		i++;
	}
	if (i < dsize)
		dest[len + i] = '\0';
	return (min(len, dsize) + ft_strlen(src));
}
