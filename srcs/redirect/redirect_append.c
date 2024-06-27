/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_append.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:33:38 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/05/13 01:16:55 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// take redirect append operator as token then set fd and save it
int	redirect_append(t_token *token, t_values *vals)
{
	t_token *temp;
	int		fd;
	int		fd_stashed;

	temp = token->next;
	fd = open(temp->value, O_WRONLY | O_CREAT | O_APPEND);
	if (fd < 0)
	{
		error_io(temp->value, vals);
		return (FAILURE);
	}
	fd_stashed = stash_fd(STDOUT);
	save_fd(fd_stashed, STDOUT, vals);
	dup2(fd, STDOUT);
	close(fd);
	return (SUCCESS);
}
