/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:33:38 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/07/01 08:38:25 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// take redirect in operator as token then set fd and save it
int	redirect_input(t_token *token, t_values *vals)
{
	t_token	*temp;
	int		fd;
	int 	fd_stashed;

	temp = token->next;
	fd = open(temp->value, O_RDONLY);
	if (fd < 0)
	{
		error_io(temp->value, vals);
		return (FAILURE);
	}
	fd_stashed = stash_fd(STDIN_FILENO);
	save_fd(fd_stashed, STDIN_FILENO, vals);
	dup2(fd, STDIN_FILENO);
	close(fd);
	return (SUCCESS);
}
