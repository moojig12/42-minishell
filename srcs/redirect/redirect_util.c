/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_util.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:33:38 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/05/06 21:48:14 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_ios	*init_ios(int fd, int old_fd)
{
	t_ios	*io;

	io = (t_ios *) malloc(sizeof(t_ios));
	if (io == NULL)
		return (NULL);
	io->fd = fd;
	io->old_fd = old_fd;
	io->next = NULL;
	// io->prev = NULL;
	return (io);
}

int	save_fd(int fd, int old_fd, t_values *val)
{
	t_ios	*new_io;
	t_ios	*head;
	// t_ios	*temp;

	new_io = init_ios(fd, old_fd);
	if (new_io == NULL)
		return (FAILURE);
	head = val->head_io;
	if (head == NULL)
	{
		val->head_io = new_io;
		// new_io->next = NULL;
		// new_io->prev = NULL;
		return (SUCCESS);
	}
	// temp = head->next;
	new_io->next = head->next;
	// if (temp != NULL)
		// temp->prev = new_io;
	// new_io->prev = head;
	head->next = new_io;
	return (SUCCESS);
}
