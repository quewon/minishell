/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 00:29:59 by qchin             #+#    #+#             */
/*   Updated: 2025/11/19 15:58:05 by qchin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while (i < (n - 1) && s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			break ;
		i++;
	}
	return (s1[i] - s2[i]);
}
/*
#include <string.h>
#include <stdio.h>
int	main(int argc, char **argv)
{
	if (argc > 2)
	{
		printf("%d\n", ft_strncmp(argv[1], argv[2], ft_atoi(argv[3])));
		printf("%d\n", strncmp(argv[1], argv[2], ft_atoi(argv[3])));
	}
	return (1);
}
*/
