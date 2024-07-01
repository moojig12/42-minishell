/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_redirection.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:33:38 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/06/30 23:28:20 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//Set up the input and output pipes for communication.
int	set_pipe_io(int command_count, int **pipe_fds_array, int total_commands)
{
	int	*last_pipe;
	int	*current_pipe;

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
	return (EXIT_SUCCESS);
}

int close_past_parent_pipe(int **pipe_fds_array, int count)
{
	close(pipe_fds_array[count - 1][PIPE_WRITE_IN]);
	close(pipe_fds_array[count - 1][PIPE_READ_FROM]);
	return (EXIT_SUCCESS);
}
