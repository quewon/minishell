/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 11:08:58 by qchin             #+#    #+#             */
/*   Updated: 2025/11/19 15:45:23 by qchin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	len;
	char	*s;

	start = 0;
	end = ft_strlen(s1);
	if (ft_strlen(s1) > 0)
	{
		while (s1[start] && ft_strchr(set, s1[start]))
			start++;
		while (end > start && ft_strchr(set, s1[end - 1]))
			end--;
	}
	len = end - start;
	s = (char *)malloc(len + 1);
	if (!s)
		return (NULL);
	ft_memcpy(s, (char *)s1 + start, len);
	s[len] = '\0';
	return (s);
}
/*
#include <stdio.h>
int	main(int argc, char **argv)
{
	if (argc > 0)
	{
		printf("%s\n", ft_strtrim(argv[1], argv[2]));
	}
}
*/
