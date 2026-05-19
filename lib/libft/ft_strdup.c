/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 09:54:06 by qchin             #+#    #+#             */
/*   Updated: 2025/11/16 09:59:36 by qchin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*p;
	size_t	size;

	size = ft_strlen(s) + 1;
	p = (char *)malloc(size);
	if (!p)
		return (NULL);
	ft_memcpy(p, s, size);
	return (p);
}
