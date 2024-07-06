/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_output.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:33:38 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/07/01 08:39:10 by yjinnouc         ###   ########.fr       */
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
	fd = open(temp->value, O_WRONLY | O_CREAT | O_TRUNC);
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
