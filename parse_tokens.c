/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tokens.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quewonchin <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 22:38:39 by quewonchin        #+#    #+#             */
/*   Updated: 2026/07/13 22:38:41 by quewonchin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*flatten_token(t_token *token)
{
	char		*expanded;
	char		*str;
	t_fragment	*fragment;

	str = NULL;
	fragment = token->fragments;
	while (fragment)
	{
		expanded = fragment->data;
		if (fragment->data[0] == '$' && fragment->expandable)
		{
			expanded = getenv(fragment->data + 1);
		}
		if (!str)
		{
			str = malloc(ft_strlen(expanded));
			ft_strlcpy(str, fragment->data, ft_strlen(expanded) + 1);
		} else
		{
			ft_strcat(&str, expanded);
		}
		fragment = fragment->next;
	}
	return (str);
}

static t_job	*new_job()
{
	t_job	*job;

	job = malloc(sizeof(t_job));
	job->command = NULL;
	job->pipe = NULL;
	job->job = NULL;
	return (job);
}

static t_command	*new_command()
{
	t_command	*command;

	command = malloc(sizeof(t_command));
	command->command = malloc(sizeof(t_simple_command));
	command->command->pathname = NULL;
	command->command->tokenlist = NULL;
	command->redirect = NULL;
	command->filename = NULL;
	return (command);
}

static t_token	*copy_token(t_token *token)
{
	t_token *copy;

	copy = malloc(sizeof(t_token));
	copy->fragments = token->fragments;
	copy->type = token->type;
	copy->next = NULL;
	return (copy);
}

static t_token	*last(t_token *token)
{
	if (token == NULL)
		return (NULL);
	while (token->next)
		token = token->next;
	return (token);
}

t_job	*parse_tokens(t_token *token)
{
	t_job		*job;
	t_job		*current_job;
	t_simple_command	*scommand;

	job = new_job();
	current_job = job;
	while (token)
	{
		if (token->type == 0)
		{
			if (current_job->command == NULL)
			{
				current_job->command = new_command();
				scommand = current_job->command->command;
				scommand->pathname = flatten_token(token);
			}
			else if (current_job->command->redirect == NULL)
			{
				if (scommand->tokenlist == NULL)
					scommand->tokenlist = copy_token(token);
				else
					last(scommand->tokenlist)->next = copy_token(token);
			}
			else
			{
				current_job->command->filename = flatten_token(token);
			}
		}
		else if (token->type == 1 || token->type == 2 || token->type == '>' || token->type == '<')
		{
			if (current_job->command == NULL)
				current_job->command = new_command();
			current_job->command->redirect = copy_token(token);
		}
		else if (token->type == '|')
		{
			if (current_job->command == NULL)
			{
				printf("parse error near '|'\n");
			}
			else
			{
				current_job->pipe = copy_token(token);
				current_job->job = new_job();
				current_job = new_job();
			}
		}
		token = token->next;
	}
	print_job(0, job);
	return (job);
}
