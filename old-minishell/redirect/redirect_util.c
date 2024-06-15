/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_util.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:33:38 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/05/12 22:27:58 by yjinnouc         ###   ########.fr       */
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
	return (io);
}

int	save_fd(int fd, int old_fd, t_values *vals)
{
	t_ios	*new_io;
	t_ios	*head;

	new_io = init_ios(fd, old_fd);
	if (new_io == NULL)
		return (FAILURE);
	head = vals->head_io;
	if (head != NULL)
		new_io->next = head;
	vals->head_io = new_io;
	return (SUCCESS);
}
