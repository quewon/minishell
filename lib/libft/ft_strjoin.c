/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 10:59:06 by qchin             #+#    #+#             */
/*   Updated: 2025/11/16 11:08:35 by qchin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*p;
	size_t	len;

	len = ft_strlen(s1) + ft_strlen(s2);
	p = (char *)malloc(len + 1);
	if (!p)
		return (NULL);
	ft_memcpy(p, s1, ft_strlen(s1));
	ft_memcpy(p + ft_strlen(s1), s2, ft_strlen(s2));
	p[len] = '\0';
	return (p);
}
