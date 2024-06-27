/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_heredoc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:33:38 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/05/13 01:42:36 by yjinnouc         ###   ########.fr       */
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
	fd_stashed = stash_fd(STDIN);
	save_fd(fd_stashed, STDIN, vals);
	dup2(fd, STDIN);
	close(fd);
	return (SUCCESS);
}

int	redirect_heredoc(t_token *token, t_values *vals)
{
	int		fd;
	char	*line;
	char	*delimiter;

	fd = open(TMP_FILENAME, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
	{
		perror("File not found");
		return (FILE_NF);
	}
	delimiter = token->next->value;
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
		// line = process_env_heredocs(line, vals);
		// TODO: need to add quoted delimiter?
		ft_putstr_fd(line, fd);
		ft_putstr_fd("\n", fd);
		free(line);
	}
	close(fd);
	redirect_heredoc_input(vals);
	return (SUCCESS);
}
