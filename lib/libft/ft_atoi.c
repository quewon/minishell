/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 08:51:33 by qchin             #+#    #+#             */
/*   Updated: 2025/11/16 13:27:29 by qchin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *s)
{
	long	r;
	int		sign;
	char	*sp;

	sp = (char *)s;
	r = 0;
	sign = 1;
	while (*sp == ' ' || (*sp >= '\t' && *sp <= '\r'))
		sp++;
	if (*sp == '-' || *sp == '+')
	{
		if (*sp == '-')
			sign = -1;
		sp++;
	}
	while (ft_isdigit(*sp))
	{
		r = (*sp - '0') + (r * 10);
		sp++;
	}
	return ((int)(r * sign));
}
/*
#include <stdio.h>
#include <stdlib.h>
int	main(int argc, char **argv)
{
	if (argc > 0)
	{
		printf("%d\n", ft_atoi(argv[1]));
		printf("%d\n", atoi(argv[1]));
	}
}
*/
