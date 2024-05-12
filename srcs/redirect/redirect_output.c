/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_output.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:33:38 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/05/06 21:52:46 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// take redirect out operator as token then set fd and save it
int	redirect_output(t_token *token, t_values *val)
{
	t_token	*temp;
	int		fd;

    temp = token->next;
	fd = open(temp->value, O_WRONLY | O_CREAT | O_TRUNC);
	// printf("fd: %d\n", fd); // TODO: remove later
	if (fd < 0)
	{
        // handle_error
		return (FAILURE);
	}
	save_fd(fd, STDOUT, val);
	dup2(fd, STDOUT);
	close(fd);
	return (SUCCESS);
}
