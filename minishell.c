/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qixu <qixu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 16:25:02 by quewonchin        #+#    #+#             */
/*   Updated: 2026/05/19 19:05:05 by qixu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void run(char **tokens)
{
	char	*command;
	char	*argument;

	command = tokens[0];
	argument = tokens[1];
	
	if (ft_strncmp(command, "echo", ft_strlen(command)) == 0)
	{
		printf("%s", argument);
	}
}

int	main(void)
{
	char	*buffer;
	char	**tokens;

	buffer = readline("$ ");
	tokens = ft_split(buffer, ' ');

	run(tokens);
}