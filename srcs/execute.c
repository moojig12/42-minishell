/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandakh <nmandakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 18:08:23 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/06/19 17:38:53 by nmandakh         ###   ########.fr       */
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
	set_pipe_io(index_command, pipe_fds_array, total_commands);
	if (set_redirect(tokens, index_command, vals) == FAILURE)
		exit (FAILURE);
	if (vals->execute_error == TRUE)
	{
		reset_redirect(vals);
		exit (FAILURE);
	}
	argv = tokens_to_argv(tokens, index_command);
	pgr = find_pgr(argv[0], vals);
	// print_commands(pgr, argv, index_command, total_commands);
	if (pgr == NULL)
		exit_command_not_found(argv[0], argv, vals);
	if (is_builtin(pgr))
		execute_builtin(argv, vals);
	else
		execve(pgr, argv, vals->env);
	// reset_redirect(vals);
	free(argv);
	free(pgr);
	exit (SUCCESS);
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
	while (count < total_commands && vals->execute_error == FALSE)
	{
		if (count < total_commands - 1)
			pipe(pipe_fds_array[count]);
		pid = fork();
		if (pid == 0)
			execute_commands(tokens, count, pipe_fds_array, vals);
		if (pid < 0)
			vals->last_error_code = 1;
		if (count > 0)
		{
			close(pipe_fds_array[count - 1][PIPE_WRITE_IN]);
			close(pipe_fds_array[count - 1][PIPE_READ_FROM]);
		}
		waitpid(pid, &status, 0);
		if (WIFEXITED(status))
			set_error_waitpid(status, vals);
		count++;
	}
	return (SUCCESS);
}

int	execute_wrapper(t_token *tokens, t_values *vals)
{
	int		**pipe_fds_array;
	int		total_commands;
	char	**temp;

	total_commands = count_commands(tokens);
	if (total_commands == 1 && is_builtin(tokens->value))
	{
		temp = tokens_to_argv(tokens, 0);
		set_redirect(tokens, 0, vals);
		if (vals->execute_error == FALSE)
			execute_builtin(temp, vals);
		reset_redirect(vals);
		free_array(temp);
	}
	else
	{
		pipe_fds_array = calloc_int_array(total_commands, 2);
		// if (pipe_fds_array == NULL)
		// 	exit_with_perror("calloc_int_array()", NULL, NULL);
		fork_process(tokens, pipe_fds_array, vals);
		free_int_array(pipe_fds_array, total_commands);
		reset_redirect(vals);
	}
	return (SUCCESS);
}
