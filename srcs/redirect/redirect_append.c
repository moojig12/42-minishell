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

	temp = token->next;
	fd = open(temp->value, O_WRONLY | O_CREAT | O_APPEND);
	if (fd < 0)
	{
		error_io(temp->value, vals);
		return (FAILURE);
	}
	save_fd(fd, STDOUT, vals);
	dup2(fd, STDOUT);
	return (SUCCESS);
}
