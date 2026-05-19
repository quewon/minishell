/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 12:22:31 by qchin             #+#    #+#             */
/*   Updated: 2025/11/16 17:09:19 by qchin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	count_digits(int n, int *digits, long *i)
{
	long	ncopy;

	*digits = 1;
	*i = 1;
	ncopy = n;
	if (n < 0)
		ncopy = -ncopy;
	while (ncopy / *i >= 10)
	{
		*i *= 10;
		*digits += 1;
	}
}

char	*ft_itoa(int n)
{
	char	*s;
	long	i;
	long	ncopy;
	int		digits;

	count_digits(n, &digits, &i);
	s = (char *)malloc(digits + 1 + (n < 0));
	if (!s)
		return (NULL);
	digits = 0;
	ncopy = n;
	if (n < 0)
	{
		ncopy = -ncopy;
		s[digits++] = '-';
	}
	while (i >= 1)
	{
		s[digits++] = (ncopy / i) + '0';
		ncopy -= (ncopy / i) * i;
		i /= 10;
	}
	s[digits] = '\0';
	return (s);
}
/*
#include <stdio.h>
#include <stdlib.h>
int	main(int argc, char **argv)
{
	if (argc > 1)
	{
		printf("%s\n", ft_itoa(atoi(argv[1])));
	}
}
*/
