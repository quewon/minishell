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

void run(t_token *token)
{
	t_token	*command;
	t_token	*argument;

	command = token;
	argument = token->next;
	
	if (ft_strncmp(command->data, "echo", ft_strlen(command->data)) == 0)
	{
		printf("%s", argument->data);
	}

	// single quotes and double quotes
	// environment variables ($)
	// pathnames
	// redirections (<, >, <<, >>)
	// pipes (|)
	// $?
	// commands: echo, cd, pwd, export, unset, env, exit
}

int	main(void)
{
	char	*buffer;
	t_token	*tokens;

	while (1)
	{
		buffer = readline("$ ");
		tokens = tokenize(buffer);
		parse_tokens(tokens);
		// run(tokens);
	}

	return (EXIT_SUCCESS);
}