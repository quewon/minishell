/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 15:20:55 by qchin             #+#    #+#             */
/*   Updated: 2025/11/16 13:24:02 by qchin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char	*sp;

	sp = s;
	while (n--)
		sp[n] = c;
	return (s);
}
/*
#include <stdio.h>
#include <string.h>
int	main()
{
	int	a[] = { 1, 2, 3, 4, 5 };
	size_t	size = sizeof(int) * 5;
	int	i = 0;

	ft_memset(a, 0, size);

	while (i < 5)
		printf("%d ", a[i++]);
	printf("\n");
	return 0;
}
*/
