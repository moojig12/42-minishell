/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 18:08:23 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/04/03 18:23:45 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int execute(int argc, char **argv, char **envp)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == 0)
	{
		if (execve(argv[0], argv, envp) == -1)
		{
			perror("execve");
			exit(1);
		}
		else
			return (SUCCESS);
	}
	else if (pid < 0)
	{
		perror("fork");
		exit(1);
	}
	else
		waitpid(pid, &status, 0);
	return (SUCCESS);
}
