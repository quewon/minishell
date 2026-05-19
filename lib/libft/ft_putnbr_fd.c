/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 13:02:37 by qchin             #+#    #+#             */
/*   Updated: 2025/11/16 13:11:39 by qchin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	ncopy;
	char	c;
	long	i;

	ncopy = n;
	if (n < 0)
	{
		write(fd, "-", 1);
		ncopy = -ncopy;
	}
	i = 1;
	while (ncopy / i >= 10)
		i *= 10;
	while (i >= 1)
	{
		c = (ncopy / i) + '0';
		write(fd, &c, 1);
		ncopy -= (ncopy / i) * i;
		i /= 10;
	}
}
