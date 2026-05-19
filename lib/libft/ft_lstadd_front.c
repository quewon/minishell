/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 18:04:35 by qchin             #+#    #+#             */
/*   Updated: 2025/11/16 18:38:18 by qchin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}
/*
#include <stdio.h>
int	main(void)
{
	t_list *node1 = ft_lstnew("first node");
	t_list *node2 = ft_lstnew("second node");
	t_list **list = &node2;
	ft_lstadd_front(list, node1);
	while (*list)
	{
		printf("%s\n", (char *)((*list)->content));
		*list = (*list)->next;
	}
}
*/
