#include "minishell.h"

static char *run_scommand(t_simple_command *command, char *input)
{
    char    *output;

    output = NULL;
    (void)command;
    (void)input;
    return (output);
}

static char *run_command(t_command *command, char *input)
{
    char    *output;

    output = NULL;
    if (command->command)
        output = run_scommand(command->command, input);
    if (command->redirect)
    {
        //redirect output
        int fd = open(command->filename, O_WRONLY);
        write(fd, output, ft_strlen(output));
    }
    return (output);
}

char    *run_job(t_job *job, char *input)
{
    char    *output;

    output = NULL;
    if (job->command)
        output = run_command(job->command, input);
    if (job->pipe)
        output = run_job(job->job, output);
    return (output);
}