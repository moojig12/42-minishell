/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:33:38 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/05/07 10:15:06 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	set_pipe_io(int command_count, int **pipe_fds_array, int total_commands)
{
	int	*current_pipe;
	int	*last_pipe;

	if (0 < command_count)
	{
		last_pipe = pipe_fds_array[command_count - 1];
		dup2(last_pipe[PIPE_READ_FROM], STDIN_FILENO);
		close(last_pipe[PIPE_WRITE_IN]);
		close(last_pipe[PIPE_READ_FROM]);
	}
	if (command_count < total_commands - 1)
	{
		current_pipe = pipe_fds_array[command_count];
		dup2(current_pipe[PIPE_WRITE_IN], STDOUT_FILENO);
		close(current_pipe[PIPE_WRITE_IN]);
		close(current_pipe[PIPE_READ_FROM]);
	}
	return (SUCCESS);
}

int set_redirect(t_token *head, int index_command, t_values *vals)
{
	t_token	*temp;

	temp = get_command_head(head, index_command);
	temp = get_next_redirection(temp);
	while (temp != NULL)
	{
		if (temp->redirect_type == REDIRECT_IN)
			redirect_input(temp, vals);
		else if (temp->redirect_type == REDIRECT_OUT)
			redirect_output(temp, vals);
		else if (temp->redirect_type == REDIRECT_HEREDOC)
			redirect_heredoc(temp, vals);
		else if (temp->redirect_type == REDIRECT_APPEND)
			redirect_append(temp, vals);
		temp = get_next_redirection(temp);
	}
	return (SUCCESS);
}

int reset_redirect(t_values *vals)
{
	t_ios	*temp;
	t_ios	*next;

	temp = vals->head_io;
	while (temp != NULL)
	{
		dup2(temp->fd, temp->old_fd);
		// close(temp->old_fd);
		next = temp->next;
		free(temp);
		temp = next;
	}
	vals->head_io = NULL;
	return (SUCCESS);
}