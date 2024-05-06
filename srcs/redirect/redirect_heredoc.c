/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_heredoc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:33:38 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/05/07 10:42:11 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	heredoc_child_process(t_token *token, int *fds)
{
	char	*line;
	char	*delimiter;

	delimiter = token->next->value;
	dup2(fds[PIPE_WRITE_IN], STDOUT);
	close(fds[PIPE_READ_FROM]);
	while (1)
	{
		line = readline("> ");
		if (line == NULL)
			break ;
		if (ft_strcmp(line, delimiter) == 0)
		{
			free(line);
			break ;
		}
		// TODO: need to replace val?
		// TODO: need to add quoted delimiter?
		ft_putstr_fd(line, fds[PIPE_WRITE_IN]);
		ft_putstr_fd("\n", fds[PIPE_WRITE_IN]);
		free(line);
	}
	close(fds[PIPE_WRITE_IN]);
	exit(EXIT_SUCCESS);
}

// take redirect heredoc operator as token then set fd and save it
int	redirect_heredoc(t_token *token, t_values *val)
{
    int		fds[2];
	int		pid;

	pipe(fds);
	pid = fork();
	if (pid == 0)
		heredoc_child_process(token, fds);
	else if (pid < 0)
		exit(EXIT_FAILURE); // TODO: fix error handling
	close(fds[PIPE_WRITE_IN]);
	dup2(fds[PIPE_READ_FROM], STDIN);
	save_fd(fds[PIPE_READ_FROM], STDIN, val);
	waitpid(pid, NULL, 0);
	return (SUCCESS);
}