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

void	init_token(t_token *token, int datasize)
{
	token->data = malloc(datasize + 1);
	token->data[0] = 0;
	// tok->type = 0;
	token->next = NULL;
}

void	print_tokens(t_token *token)
{
	while (token)
	{
		printf("[%s] ", token->data);
		token = token->next;
	}
}

t_token	*split_tokens(char *buffer, int size)
{
	int	i;
	int	j;
	char	c;
	t_token	*token;
	t_token	*list;
	int	state;

	token = malloc(sizeof(t_token));
	init_token(token, size);
	list = token;
	i = 0;
	j = 0;
	state = 0; // 0: normal mode, 1: quoted mode
	while (buffer[i] != '\0')
	{
		c = buffer[i];

		if (c == '\"')
		{
			if (state == 0)
			{
				state = 1;
			}
			else
			{
				state = 0;
			}
		}
		else if (state == 0 && c == ' ')
		{
			token->data[j] = 0;
			j = 0;
			token->next = malloc(sizeof(t_token));
			token = token->next;
			init_token(token, size);
		}
		else
		{
			token->data[j++] = c;
		}

		i++;
	}
	return (list);
}

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
	// pathnames
	// redirections (<, >, <<, >>)
	// pipes (|)
	// environment variables ($)
	// $?
	// commands: echo, cd, pwd, export, unset, env, exit
}

int	main(void)
{
	char	*buffer;
	t_token	*tokens;

	buffer = readline("$ ");
	tokens = split_tokens(buffer, 1000);
	run(tokens);
}