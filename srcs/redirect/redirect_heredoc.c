/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_heredoc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:33:38 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/05/06 21:52:32 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// take redirect heredoc operator as token then set fd and save it
int	redirect_heredoc(t_token *token, t_values *val)
{
	t_token *temp;
    int     fd;

	temp = token->next;
	fd = open(temp->value, O_RDONLY);
	// printf("fd: %d\n", fd); // TODO: remove later
	if (fd < 0)
	{
		// handle_error
		return (FAILURE);
	}
	save_fd(fd, STDIN, val);
	dup2(fd, STDIN);
	close(fd);
	return (SUCCESS);
}
