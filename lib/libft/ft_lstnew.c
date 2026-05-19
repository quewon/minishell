/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 17:37:52 by qchin             #+#    #+#             */
/*   Updated: 2025/11/16 19:26:46 by qchin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}
/*
#include <stdio.h>
int	main(void)
{
	char *content = "hello!";
	t_list *lst;
	lst = ft_lstnew(content);
	while (lst)
	{
		printf("%s\n", (char *)lst->content);
		lst = lst->next;
	}
}
*/
