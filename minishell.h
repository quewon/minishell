/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qixu <qixu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 16:54:49 by qixu              #+#    #+#             */
/*   Updated: 2026/05/19 19:01:39 by qixu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "lib/libft/libft.h"
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>

typedef struct s_fragment {
    char                *data;
    int                 expandable;
    struct s_fragment   *next;
} t_fragment;
typedef struct s_token {
    t_fragment     *fragments;
    int            type;
    struct s_token *next;
} t_token;

typedef struct s_simple_command {
    char    *pathname;
    t_token *tokenlist;
} t_simple_command;
typedef struct s_command {
    t_simple_command    *command;
    t_token             *redirect;
    char                *filename;
} t_command;
typedef struct s_job {
    t_command       *command;
    t_token         *pipe;
    struct s_job    *job;
} t_job;

void	print_tokens(t_token *token);
void	print_job(int indent, t_job *job);
t_token	*tokenize(char *buffer);
t_job	*parse_tokens(t_token *token);
char    *run_job(t_job *job, char *input);

#endif