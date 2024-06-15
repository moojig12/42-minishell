/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:33:38 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/05/13 01:16:32 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// take redirect in operator as token then set fd and save it
int	redirect_input(t_token *token, t_values *vals)
{
	t_token	*temp;
	int		fd;

	temp = token->next;
	fd = open(temp->value, O_RDONLY);
	if (fd < 0)
	{
		// handle_error
		error_io(temp->value, vals);
		return (FAILURE);
	}
	save_fd(fd, STDIN, vals);
	dup2(fd, STDIN);
	close(fd);
	return (SUCCESS);
}
