/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 18:08:23 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/04/16 18:20:33 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	count_token(t_token *tokens)
{
	int		count;
	t_token	*temp;

	count = 0;
	temp = tokens;
	while (temp != NULL)
	{
		count++;
		temp = temp->next;
	}
	return (count);
}

char	**tokens_to_args(t_token *tokens)
{
	char	**args;
	t_token *temp;
	int		i;

	args = malloc(sizeof(char *) * (count_token(tokens) + 1));
	if (args == NULL)
		exit_wi_perr("malloc", NULL, NULL);
	temp = tokens;
	i = 0;
	while (temp != NULL)
	{
		args[i] = ft_strdup(temp->value);
		if (args[i] == NULL)
			exit_wi_perr("malloc", NULL, NULL);
		temp = temp->next;
		i++;
	}
	args[i] = NULL;
	return (args);
}

int	execute(t_token	*tokens, char **env)
{
	char	**argv;
	char	*pgr_path;

	pgr_path = NULL;
	argv = tokens_to_args(tokens);
	printf("argv[0]: %s\n", argv[0]);
	if (is_builtin(argv[0]) == FALSE)
	{
		pgr_path = find_pgr(argv[0], env);
		printf("pgr_path: %s\n\n", pgr_path);
	}
	else
	{
		pgr_path = "-";
		execute_builtin(argv, env);
		free_args(argv);
		return (SUCCESS);
	}
	if (pgr_path == NULL)
	{
		printf("minishell: %s: command not found\n", argv[0]);
		free_args(argv);
		return (FAILURE);
	}
	if (fork_program(pgr_path, argv, env) == FAILURE)
	{
		free_args(argv);
		return (FAILURE);
	}
	return (SUCCESS);
}

int	fork_program(char *pgr_path, char **argv, char **env)
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid == 0)
	{
		if (execve(pgr_path, argv, env) == -1)
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
