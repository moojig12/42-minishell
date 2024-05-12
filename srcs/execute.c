/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 18:08:23 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/05/13 00:09:47 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_commands(char *path, char **argv, int index_command, int total_commands)
{
	fprintf(stderr, "command %i: %s -> %s\n", index_command + 1, argv[0], path); // TODO: delete later
	if (total_commands - 1 == index_command)
		fprintf(stderr, "--------\n");
}

int	execute_commands(t_token *tokens, int index_command, \
	int **pipe_fds_array, t_values *vals)
{
	int		total_commands;
	char	**argv;
	char	*pgr;

	total_commands = count_commands(tokens);
	set_redirect(tokens, index_command, vals);
	set_pipe_io(index_command, pipe_fds_array, total_commands);
	argv = tokens_to_argv(tokens, index_command);
	pgr = find_pgr(argv[0]);
	print_commands(pgr, argv, index_command, total_commands);
	if (pgr == NULL)
	{
		exit_command_not_found(argv[0], argv, vals);
		return (FAILURE);
	}
	free(argv[0]);
	argv[0] = pgr;
	if (is_builtin(argv[0]))
		execute_builtin(argv, vals->env);
	else
		execve(argv[0], argv, vals->env);
	free_array(argv);
	reset_redirect(vals);
	return (SUCCESS);
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
			execute_commands(tokens, count, pipe_fds_array, vals);
		else if (pid < 0)
		{
			vals->last_error_code = 1;
			exit(EXIT_FAILURE); // TODO: fix error handling
		}
		else if (0 < count)
		{
			close(pipe_fds_array[count - 1][PIPE_WRITE_IN]);
			close(pipe_fds_array[count - 1][PIPE_READ_FROM]);
		}
		count++;
	}
	waitpid(pid, &status, 0);
	if (status == -1)
		set_error_waitpid(status, vals);
	return (SUCCESS);
}

int	execute_wrapper(t_token *tokens, t_values *vals)
{
	int		total_commands;
	char	**argv;
	int		**pipe_fds_array;

	total_commands = count_commands(tokens);
	if (total_commands == 1 && is_builtin(tokens->value))
	{
		argv = tokens_to_argv(tokens, 0);
		execute_builtin(argv, vals);
		free_array(argv);
	}
	else
	{
		pipe_fds_array = calloc_int_array(total_commands, 2);
		// if (pipe_fds_array == NULL)
		// 	exit_with_perror("calloc_int_array()", NULL, NULL);
		fork_process(tokens, pipe_fds_array, vals);
		free_int_array(pipe_fds_array, total_commands);
	}
	return (SUCCESS);
}
