/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_heredoc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandakh <nmandakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:33:38 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/07/08 14:15:21 by nmandakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	redirect_heredoc_input(t_values *vals)
{
	int	fd;
	int	fd_stashed;

	fd = open(TMP_FILENAME, O_RDONLY);
	if (fd == -1)
	{
		perror("File not found");
		return (FILE_NF);
	}
	fd_stashed = stash_fd(STDIN_FILENO);
	save_fd(fd_stashed, STDIN_FILENO, vals);
	dup2(fd, STDIN_FILENO);
	close(fd);
	return (EXIT_SUCCESS);
}

int	heredoc_loop(char *line, char *delimiter, int fd)
{
	line = readline("> ");
	if (line == NULL)
		return (1);
	if (ft_strcmp(line, delimiter) == 0)
	{
		free(line);
		return (1);
	}
	ft_putstr_fd(line, fd);
	ft_putstr_fd("\n", fd);
	free(line);
	return (0);
}

int	redirect_heredoc(t_token *token, t_values *vals)
{
	int		fd;
	char	*line;
	char	*delimiter;

	line = NULL;
	fd = open(TMP_FILENAME, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
	{
		perror("File not found");
		return (FILE_NF);
	}
	delimiter = token->next->value;
	while (1)
	{
		if (heredoc_loop(line, delimiter, fd) == 1)
			break ;
	}
	close(fd);
	redirect_heredoc_input(vals);
	return (EXIT_SUCCESS);
}
		// line = process_env_heredocs(line, vals);
		// TODO: need to add quoted delimiter?
