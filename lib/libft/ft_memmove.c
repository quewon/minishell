/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 16:39:33 by qchin             #+#    #+#             */
/*   Updated: 2025/11/19 17:06:22 by qchin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	int	i;

	if (dest < src)
	{
		i = 0;
		while ((size_t)i < n)
		{
			((char *)dest)[i] = ((char *)src)[i];
			i++;
		}
	}
	else
	{
		i = n - 1;
		while (i >= 0)
		{
			((char *)dest)[i] = ((char *)src)[i];
			i--;
		}
	}
	return (dest);
}
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int	main(int argc, char **argv)
{
	if (argc > 1)
	{
		char d[100];
		strcpy(d + 2, "123456");

		char *res = memmove(d, d + 2, atoi(argv[1]));
		printf("   memmove: %p %s\n", res, res);
		
		bzero(d, 100);
		strcpy(d + 2, "123456");
		res = memmove(d, d + 2, atoi(argv[1]));
		printf("ft_memmove: %p %s\n", res, res);
		
	}
}
*/
