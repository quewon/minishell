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

static t_token	*new_token()
{
	t_token *token;

	token = malloc(sizeof(t_token));
	token->fragments = NULL;
	token->type = 0;
	token->next = NULL;
	return (token);
}

static t_fragment	*new_fragment(int size, int expandable)
{
	t_fragment	*fragment;

	fragment = malloc(sizeof(t_fragment));
	fragment->data = malloc(size + 1);
	fragment->expandable = expandable;
	fragment->next = NULL;
	return (fragment);
}

static void	add_fragment(t_token *token, t_fragment *fragment)
{
	t_fragment		*f;

	if (token->fragments == NULL)
	{
		token->fragments = fragment;
	}
	else
	{
		f = token->fragments;
		while (f->next)
			f = f->next;
		f->next = fragment;
	}
}

t_token	*tokenize(char *buffer)
{
	t_token		*token;
	t_fragment	*fragment;
	int			f;
	t_token		*list;
	int			state;

	token = new_token();
	fragment = new_fragment(ft_strlen(buffer), 1);
	f = 0;
	list = token;
	state = 0; // 0: default, 1: single quote, 2: double quote
	while (*buffer != '\0')
	{
		if (state == 0)
		{
			if (*buffer == ' ' || *buffer == '>' || *buffer == '<' || *buffer == '|')
			{
				// whitespace, >, <, and | are token splitters
				// if token is not empty, create a new token
				if (f > 0)
				{
					add_fragment(token, fragment);
					fragment = new_fragment(ft_strlen(buffer), 1);
					f = 0;
				}
				if (token->fragments != NULL)
				{
					token->next = new_token();
					token = token->next;
				}
			}
			if (*buffer == '>' || *buffer == '<' || *buffer == '|')
			{
				if (*buffer == '>' && *(buffer + 1) == '>')
				{
					// these 3 lines only necessary for debugging
					fragment->data[0] = *buffer;
					fragment->data[1] = *(++buffer);
					fragment->data[2] = 0;
					token->type = 1;
				}
				else if (*buffer == '<' && *(buffer + 1) == '<')
				{
					// these 3 lines only necessary for debugging
					fragment->data[0] = *buffer;
					fragment->data[1] = *(++buffer);
					fragment->data[2] = 0;
					token->type = 2;
				}
				else
				{
					// these 2 lines only necessary for debugging
					fragment->data[0] = *buffer;
					fragment->data[1] = 0;
					token->type = *buffer;
				}
				add_fragment(token, fragment);
				token->next = new_token();
				token = token->next;
				fragment = new_fragment(ft_strlen(buffer), 1);
				f = 0;
			}
			else
			{
				if (*buffer == '\'')
					state = 1;
				else if (*buffer == '\"')
					state = 2;
				if (*buffer == '\'' || *buffer == '\"')
					fragment->data[f++] = *(++buffer); // for debugging
				else if (*buffer != ' ')
					fragment->data[f++] = *buffer;
			}
		}
		else if (state == 1) // quote
		{
			if (*buffer == '\'' || *buffer == '$' || *buffer == ' ')
			{
				// ', $ and whitespace are fragment splitters
				if (f > 0)
				{
					add_fragment(token, fragment);
					fragment = new_fragment(ft_strlen(buffer), 1);
					f = 0;
				}
			}
			if (*buffer == '\'')
				state = 0;
			else if (*buffer == '$')
				fragment->expandable = 0;
			if (*buffer != '\'')
				fragment->data[f++] = *buffer;
		}
		else if (state == 2) // dquote
		{
			if (*buffer == '\"' || *buffer == '$' || *buffer == ' ')
			{
				// ", $ and whitespace are fragment splitters
				if (f > 0)
				{
					add_fragment(token, fragment);
					fragment = new_fragment(ft_strlen(buffer), 1);
					f = 0;
				}
			}
			if (*buffer == '\"')
				state = 0;
			if (*buffer != '\"')
				fragment->data[f++] = *buffer;
		}
		buffer++;
	}
	if (f > 0)
		add_fragment(token, fragment);
	// print_tokens(list);
	// printf("\n");
	return (list);
}
