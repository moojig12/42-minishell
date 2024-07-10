/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandakh <nmandakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 18:08:23 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/07/08 14:12:07 by nmandakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	count_str_array(char **args)
{
	int	i;

	i = 0;
	while (args[i] != NULL)
		i++;
	return (i);
}

int	child_process(t_token *tokens, int index_command, \
	int **pipe_fds_array, t_values *vals)
{
	int		total_commands;
	char	**argv;
	char	*pgr;
	int		status;

	total_commands = count_commands(tokens);
	set_pipe_io(index_command, pipe_fds_array, total_commands);
	if (set_redirect(tokens, index_command, vals) != EXIT_SUCCESS)
		exit (EXIT_FAILURE);
	argv = tokens_to_argv(tokens, index_command);
	pgr = find_pgr(argv[0], vals);
	if (pgr == NULL)
	{
		free_int_array(pipe_fds_array, total_commands);
		exit_command_not_found(argv[0], argv, vals);
	}
	if (is_builtin(pgr))
		status = execute_builtin(argv, vals);
	else
		status = execve(pgr, argv, vals->env);
	reset_redirect(vals);
	free_array(argv);
	free(pgr);
	free_int_array(pipe_fds_array, total_commands);
	free_vals_elements(vals);
	exit (status);
}

int	fork_process(t_token *head_token, int **pipe_fds_array, t_values *vals)
{
	int		total_commands;
	int		command_count;
	int		status;
	pid_t	pid;

	total_commands = count_commands(head_token);
	command_count = 0;
	status = 0;
	while (command_count < total_commands && vals->execute_error == FALSE)
	{
		if (command_count < total_commands - 1)
			pipe(pipe_fds_array[command_count]);
		pid = fork();
		if (pid == 0)
			child_process(head_token, command_count, pipe_fds_array, vals);
		else if (pid < 0)
			exit_with_perror("fork()", vals);
		else if (0 < pid && 0 < command_count)
			close_past_parent_pipe(pipe_fds_array, command_count);
		signals_hander_ignore();
		waitpid(pid, &status, 0);
		set_error_waitpid(status, vals);
		command_count++;
	}
	return (EXIT_SUCCESS);
}

/*
Prepare for execution and handle two cases:
- Single built-in command: executed in the parent process.
- Execute with pipes: executed in the child process with pipes.
*/
int	execute_wrapper(char *input, t_values *vals)
{
	int		**pipe_fds_array;
	int		total_commands;
	char	**argv;
	t_token	*head_token;

	if (lexical_analysis(input, vals) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	head_token = vals->head_token;
	total_commands = count_commands(head_token);
	if (total_commands == 1 && is_builtin(head_token->value))
	{
		argv = tokens_to_argv(head_token, 0);
		set_redirect(head_token, 0, vals);
		execute_builtin(argv, vals);
		reset_redirect(vals);
		free_array(argv);
	}
	else
	{
		pipe_fds_array = calloc_int_array(total_commands, 2);
		if (pipe_fds_array == NULL)
			return (system_error(MEM_ERROR));
		fork_process(head_token, pipe_fds_array, vals);
		free_int_array(pipe_fds_array, total_commands);
	}
	return (EXIT_SUCCESS);
}
