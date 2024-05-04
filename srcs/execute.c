/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 18:08:23 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/05/04 10:59:36 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void print_commands(char **argv, int index_command, int total_commands)
{
	fprintf(stderr, "argv[0] of command %i: %s\n", index_command + 1, argv[0]); // TODO: delete later
	if (total_commands - 1 == index_command)
		fprintf(stderr, "--------\n");
}

int	execute_commands(t_token *tokens, int index_command, \
	int **pipe_fds_array, char **env)
{
	int		total_commands;
	char	**argv;

	total_commands = count_commands(tokens);
	set_pipe_io(index_command, pipe_fds_array, total_commands);
	// set_redirect()
	argv = tokens_to_argv(tokens, index_command);
	argv[0] = find_pgr(argv[0], env);
	print_commands(argv, index_command, total_commands);
	if (!argv[0])
	{
		free_array_err(argv);
		return (0);
	}
	if (is_builtin(argv[0]))
		execute_builtin(argv, env);
	else
		execve(argv[0], argv, env);
	free(argv);
	exit(EXIT_SUCCESS);
}

int	fork_process(t_token *tokens, int **pipe_fds_array, t_values *vals)
{
	int		total_commands;
	pid_t	pid;
	int		status;
	int		count;

	total_commands = count_commands(tokens);
	count = 0;
	status = 0;
	while (count < total_commands)
	{
		if (count < total_commands - 1)
			pipe(pipe_fds_array[count]);
		pid = fork();
		if (pid == 0)
			execute_commands(tokens, count, pipe_fds_array, vals->env);
		else if (pid < 0)
			exit(EXIT_FAILURE); // TODO: fix error handling
		else if (0 < count)
		{
			close(pipe_fds_array[count - 1][PIPE_WRITE_IN]);
			close(pipe_fds_array[count - 1][PIPE_READ_FROM]);
		}
		count++;
	}
	waitpid(pid, &status, 0);
	if (status == -1)
		exit_with_perror("waitpid()", NULL, NULL);
	return (SUCCESS);
}

int	execute_wrapper(t_token *tokens, t_values *vals)
{
	int	**pipe_fds_array;
	int	total_commands;

	total_commands = count_commands(tokens);
	if (total_commands == 1 && is_builtin(tokens->value))
	{
		// set_redirect()
		execute_builtin(tokens_to_argv(tokens, 0), vals->env);
	}
	else
	{
		pipe_fds_array = calloc_int_array(total_commands, 2);
		if (pipe_fds_array == NULL)
			exit_with_perror("calloc_int_array()", NULL, NULL);
		fork_process(tokens, pipe_fds_array, vals);
		free_int_array(pipe_fds_array, total_commands);
	}
	return (SUCCESS);
}
