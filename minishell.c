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

int	main(void)
{
	char	*buffer;
	t_token	*tokens;
	t_job	*job;
	char	*output;

	while (1)
	{
		buffer = readline("$ ");
		if (buffer == NULL) {
			break ;
		}
		tokens = tokenize(buffer);
		job = parse_tokens(tokens);
		output = run_job(job, NULL);
		if (output)
			printf("%s", output);
		else
			printf("\n");
	}
	return (EXIT_SUCCESS);
}