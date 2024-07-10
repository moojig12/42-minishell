/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_output.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandakh <nmandakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:33:38 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/07/10 17:26:11 by nmandakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// take redirect out operator as token then set fd and save it
int	redirect_output(t_token *token, t_values *vals)
{
	t_token	*temp;
	int		fd;
	int		fd_stashed;

	temp = token->next;
	fd = open(temp->value, O_WRONLY | O_CREAT | O_TRUNC | O_RDONLY);
	if (fd < 0)
	{
		error_io(temp->value, vals);
		return (EXIT_FAILURE);
	}
	fd_stashed = stash_fd(STDOUT_FILENO);
	save_fd(fd_stashed, STDOUT_FILENO, vals);
	dup2(fd, STDOUT_FILENO);
	close(fd);
	return (EXIT_SUCCESS);
}
