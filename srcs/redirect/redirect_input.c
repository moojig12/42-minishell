/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:33:38 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/06/24 22:04:01 by yjinnouc         ###   ########.fr       */
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
	fd_stashed = stash_fd(STDIN);
	save_fd(fd_stashed, STDIN, vals);
	dup2(fd, STDIN);
	close(fd);
	return (SUCCESS);
}
