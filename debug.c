/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quewonchin <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 22:39:05 by quewonchin        #+#    #+#             */
/*   Updated: 2026/07/13 22:39:06 by quewonchin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_tokens(t_token *token)
{
    // t_fragment  *fragment;

	while (token)
	{
        // printf("[");
        // fragment = token->fragments;
        // while (fragment)
        // {
        //     printf("%s", fragment->data);
        //     if (fragment->next)
        //         printf("|");
        //     fragment = fragment->next;
        // }
        // printf("] ");
        printf("[%s] ", flatten_token(token));
		token = token->next;
	}
}

static void	print_simple_command(int indent, t_simple_command *command)
{
    if (command == NULL)
    {
        printf("%*ssimple command: NULL\n", indent, "");
        return ;
    }
    printf("%*ssimple command:\n", indent, "");
    indent += 2;
	printf("%*spathname: [%s]\n", indent, "", command->pathname);
	printf("%*stokens: ", indent, "");
    print_tokens(command->tokenlist);
    printf("\n");
}

static void	print_command(int indent, t_command *command)
{
    if (command == NULL)
    {
        printf("%*scommand: NULL\n", indent, "");
        return ;
    }
    printf("%*scommand:\n", indent, "");
    indent += 2;
    print_simple_command(indent, command->command);
    if (command->redirect == NULL)
    {
        printf("%*sredirect: NULL\n", indent, "");
    }
    else
    {
        printf("%*sredirect: ", indent, "");
        print_tokens(command->redirect);
        printf("\n");
    }
    if (command->filename)
        printf("%*sfilename: [%s]\n", indent, "", command->filename);
    else
        printf("%*sfilename: NULL\n", indent, "");
}

void	print_job(int indent, t_job *job)
{
    if (job == NULL)
    {
        printf("%*sjob: NULL\n", indent, "");
        return ;
    }
    printf("%*sjob:\n", indent, "");
    indent += 2;
	print_command(indent, job->command);
    if (job->pipe == NULL)
    {
        printf("%*spipe: NULL\n", indent, "");
    }
    else
    {
        printf("%*spipe: ", indent, "");
        print_tokens(job->pipe);
        printf("\n");
    }
    print_job(indent, job->job);
}
