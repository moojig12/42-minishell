/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_util.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:33:38 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/06/24 21:37:11 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_ios	*init_ios(int save_fd, int dest_fd)
{
	t_ios	*io;

	io = (t_ios *) malloc(sizeof(t_ios));
	if (io == NULL)
		return (NULL);
	io->save_fd = save_fd;
	io->dest_fd = dest_fd;
	io->next = NULL;
	return (io);
}

int	save_fd(int save_fd, int dest_fd, t_values *vals)
{
	t_ios	*new_io;
	t_ios	*head;

	new_io = init_ios(save_fd, dest_fd);
	if (new_io == NULL)
		return (EXIT_FAILURE);
	head = vals->head_io;
	if (head != NULL)
		new_io->next = head;
	vals->head_io = new_io;
	return (EXIT_SUCCESS);
}

int	stash_fd(int fd)
{
	int	stash_fd;

	if (!is_valid_fd(fd))
	{
		errno = EBADF;
		return (EXIT_FAILURE);
	}
	stash_fd = 10;
	while (is_valid_fd(stash_fd))
		stash_fd++;
	dup2(fd, stash_fd);
	close(fd);
	return (stash_fd);
}

bool	is_valid_fd(int fd)
{
	struct stat	st;

	if (fd < 0)
		return (false);
	errno = 0;
	if (fstat(fd, &st) < 0 && errno == EBADF)
		return (false);
	return (true);
}
