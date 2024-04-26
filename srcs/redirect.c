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
