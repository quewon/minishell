/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quewonchin <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 14:38:34 by quewonchin        #+#    #+#             */
/*   Updated: 2026/07/13 14:38:35 by quewonchin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_token	*new_token(int datasize)
{
	t_token *token;

	token = malloc(sizeof(t_token));
	token->data = malloc(datasize + 1);
	token->data[0] = 0;
	token->type = 0;
	token->next = NULL;
	return (token);
}

t_token	*tokenize(char *buffer)
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
			if (*buffer == '>' || *buffer == '<' || *buffer == '|')
			{
				if (*buffer == '>' && *(buffer + 1) == '>')
				{
					token->data[0] = *buffer;
					token->data[1] = *(++buffer);
					token->data[2] = 0;
					token->type = 1;
				}
				else if (*buffer == '<' && *(buffer + 1) == '<')
				{
					token->data[0] = *buffer;
					token->data[1] = *(++buffer);
					token->data[2] = 0;
					token->type = 2;
				}
				else
				{
					token->data[0] = *buffer;
					token->data[1] = 0;
					token->type = *buffer;
				}
				token->next = new_token(ft_strlen(buffer));
				token = token->next;
			}
			else
			{
				if (*buffer == '\'' || *buffer == '\"' || *buffer == ' ')
				{
					if (i > 0)
					{
						token->data[i] = '\0';
						token->next = new_token(ft_strlen(buffer));
						token = token->next;
						i = 0;
					}
					if (*buffer == '\'')
						state = 1;
					else if (*buffer == '\"')
						state = 2;
				}
				if (*buffer != ' ')
					token->data[i++] = *buffer;
			}
		}
		else if (state == 1)
		{
			token->data[i++] = *buffer;
			if (*buffer == '\'')
				state = 0;
		}
		else if (state == 2)
		{
			token->data[i++] = *buffer;
			if (*buffer == '\"')
				state = 0;
		}
		buffer++;
	}
	if (i > 0)
	{
		token->data[i] = 0;
		i = 0;
	}
	// print_tokens(list);
	return (list);
}
