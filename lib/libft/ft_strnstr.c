/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 08:26:02 by qchin             #+#    #+#             */
/*   Updated: 2025/11/16 08:50:02 by qchin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	nsize;
	size_t	i;
	size_t	j;

	nsize = ft_strlen(needle);
	if (!nsize)
		return ((char *)haystack);
	i = 0;
	while (haystack[i] && i + nsize <= len)
	{
		j = 0;
		while (j < nsize && haystack[i + j] == needle[j])
			j++;
		if (j == nsize)
			return ((char *)haystack + i);
		i++;
	}
	return (NULL);
}
