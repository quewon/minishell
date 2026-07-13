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

t_token	*new_token(int datasize)
{
	t_token *token;

	token = malloc(sizeof(t_token));
	token->data = malloc(datasize + 1);
	token->data[0] = 0;
	token->type = 0;
	token->next = NULL;
	return (token);
}

void	print_tokens(t_token *token)
{
	while (token)
	{
		printf("[%s] ", token->data);
		token = token->next;
	}
}

t_token	*split_tokens(char *buffer)
{
	t_token	*token;
	t_token	*list;
	int	i;
	int	state;

	token = new_token(ft_strlen(buffer));
	i = 0;

	list = token;
	state = 0; // 0: default, 1: single quote, 2: double quote
	while (*buffer != '\0')
	{
		if (state == 0)
		{
			if (*buffer == '\'')
			{
				state = 1;
				token->data[i++] = '\'';
			}
			else if (*buffer == '\"')
			{
				state = 2;
				token->data[i++] = '\"';
			}
			else if (*buffer == '\\')
			{
				token->data[i++] = *(++buffer);
			}
			else if (*buffer == ' ')
			{
				if (i > 0)
				{
					token->data[i] = '\0';
					token->next = new_token(ft_strlen(buffer));
					token = token->next;
					i = 0;
				}
			}
			else if (*buffer == ';' || *buffer == '>' || *buffer == '<' || *buffer == '&' || *buffer == '|')
			{
				if (i > 0)
				{
					token->data[i] = '\0';
					token->next = new_token(ft_strlen(buffer));
					token = token->next;
					i = 0;
				}

				token->data[0] = *buffer;
				token->data[1] = 0;
				token->type = *buffer;
				token->next = new_token(ft_strlen(buffer));
				token = token->next;
			}
			else
			{
				token->data[i++] = *buffer;
			}
		}
		else if (state == 1)
		{
			token->data[i++] = *buffer;
			if (*buffer == '\'')
			{
				state = 0;
			}
		}
		else if (state == 2)
		{
			token->data[i++] = *buffer;
			if (*buffer == '\"')
			{
				state = 0;
			}
		}
		buffer++;
	}
	if (i > 0)
	{
		token->data[i] = 0;
		i = 0;
	}
	return (list);
}

// void	parse_tokens(t_token *token)
// {
// 	char	*var;
// 	char	*value;
// 	char	*beforevar;

// 	while (token)
// 	{
// 		if (token->type <= 1)
// 		{
// 			var = ft_strchr(token->data, '$');
// 			if (var != NULL)
// 				value = getenv(var + 1);
// 			else
// 				value = "";
// 			printf("%s", value);
// 		}
// 		token = token->next;
// 	}
// }

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

	buffer = readline("$ ");
	tokens = split_tokens(buffer);
	print_tokens(tokens);
	// parse_tokens(tokens);
	// run(tokens);
}