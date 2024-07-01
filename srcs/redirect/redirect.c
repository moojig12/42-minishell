/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:33:38 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/06/24 21:43:37 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	set_redirect(t_token *head, int index_command, t_values *vals)
{
	t_token	*temp;

	temp = get_command_head(head, index_command);
	temp = get_next_redirection(temp);
	while (temp != NULL && vals->execute_error == FALSE)
	{
		if (temp->redirect_type == REDIRECT_IN)
			redirect_input(temp, vals);
		else if (temp->redirect_type == REDIRECT_OUT)
			redirect_output(temp, vals);
		else if (temp->redirect_type == REDIRECT_HEREDOC)
			redirect_heredoc(temp, vals);
		else if (temp->redirect_type == REDIRECT_APPEND)
			redirect_append(temp, vals);
		temp = get_next_redirection(temp);
	}
	return (EXIT_SUCCESS);
}

int	reset_redirect(t_values *vals)
{
	t_ios	*temp;
	t_ios	*next;

	temp = vals->head_io;
	while (temp != NULL)
	{
		dup2(temp->save_fd, temp->dest_fd);
		close(temp->save_fd);
		next = temp->next;
		free(temp);
		temp = next;
	}
	vals->head_io = NULL;
	return (EXIT_SUCCESS);
}
