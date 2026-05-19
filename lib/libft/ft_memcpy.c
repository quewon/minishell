/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 16:23:20 by qchin             #+#    #+#             */
/*   Updated: 2025/11/16 13:30:34 by qchin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*dp;
	const char	*sp;

	dp = dest;
	sp = src;
	while (n--)
		*dp++ = *sp++;
	return (dest);
}
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int     main()
{
        int     a[] = { 1, 2, 3, 4, 5 };
	int	*copy = NULL;
        size_t  size = sizeof(int) * 5;
        int     i = 0;

	copy = (int *)malloc(size);
        ft_memcpy(copy, a, size);
        while (i < 5)
                printf("%d ", copy[i++]);
        printf("\n");
	free(copy);
        return 0;
}
*/
