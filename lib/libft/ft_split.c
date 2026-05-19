/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 11:43:26 by qchin             #+#    #+#             */
/*   Updated: 2025/11/16 17:07:50 by qchin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	partcount(char const *s, char c)
{
	size_t	parts;
	size_t	i;

	parts = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			parts++;
		i++;
	}
	return (parts);
}

static size_t	partlen(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

static void	*freeall(char **a, size_t p)
{
	size_t	i;

	i = 0;
	while (i < p)
		free(a[i++]);
	free(a);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**a;
	char	*sp;
	size_t	p;
	size_t	len;

	a = (char **)malloc((partcount(s, c) + 1) * sizeof(char *));
	if (!a)
		return (NULL);
	sp = (char *)s;
	p = 0;
	while (*sp)
	{
		while (*sp == c)
			sp++;
		if (!(*sp))
			break ;
		len = partlen(sp, c);
		a[p] = (char *)malloc(len + 1);
		if (!a[p])
			return (freeall(a, p));
		ft_strlcpy(a[p++], sp, len + 1);
		sp += len;
	}
	a[p] = NULL;
	return (a);
}
/*
#include <stdio.h>
int	main(int argc, char **argv)
{
	char	**a;
	int	i;

	if (argc > 2)
	{
		a = ft_split(argv[1], *argv[2]);
		if (!a)
			return 1;
		i = 0;
		while (a[i])
		{
			printf("%s\n", a[i]);
			free(a[i]);
			i++;
		}
		free(a);
	}
}
*/
