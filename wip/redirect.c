/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_io.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:33:38 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/04/23 16:13:15 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int pipe_wrapper(int *fds)
{
	if (pipe(fds) == -1)
	{
		perror("pipe"); //TODO: fix error handling
		return (FAILURE);
	}
	return (SUCCESS);
}

int type_redirect(t_token *head, int num_command)
{
	t_token *temp;
	int count_command;

	temp = head;
	count_command = 0;
	while(count_command < num_command)
	{
		if (temp->type == 2)
			count_command++;
		temp = temp->next;
	}
	while (temp != NULL && temp->type != 2)
	{
		if (temp->type > 2)
			return (temp->type);
		temp = temp->next;
	}
	return (FALSE);
}

// int set_redirect(t_token *tokens, int num_command, int *pipe_fds)
// {
// 	if (num_command != count_commands(tokens) - 1)
// 		pipe_wrapper(pipe_fds);
// 	fprintf(stderr, "pipe_fds[0]: %d\n", pipe_fds[PIPE_WRITE_IN]);
// 	fprintf(stderr, "pipe_fds[1]: %d\n", pipe_fds[PIPE_READ_FROM]);
// 	if (redirect_input(tokens, num_command) == FAILURE)
// 		return (FAILURE);
// 	if (redirect_output(tokens, num_command, pipe_fds) == FAILURE)
// 		return (FAILURE);
// 	fprintf(stderr, "stdi/o %d\n", pipe_fds[PIPE_WRITE_IN]);
// 	return (SUCCESS);
// }

int set_pipe_io(int command_count, int **pipe_fds_array, int total_commands)
{
	int *current_pipe;
	int *last_pipe;

	current_pipe = pipe_fds_array[command_count];
	last_pipe = pipe_fds_array[command_count - 1];
	if (0 < command_count)
	{
		dup2(last_pipe[PIPE_READ_FROM], STDIN_FILENO);
		close(last_pipe[PIPE_WRITE_IN]);
		close(last_pipe[PIPE_READ_FROM]);
	}
	if (command_count < total_commands - 1)
	{
		dup2(current_pipe[PIPE_WRITE_IN], STDOUT_FILENO);
		close(current_pipe[PIPE_WRITE_IN]);
		close(current_pipe[PIPE_READ_FROM]);
	}
	return (SUCCESS);
}
