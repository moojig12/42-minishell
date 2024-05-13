/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_execute.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 18:08:23 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/05/02 13:43:29 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	count_all_tokens(t_token *tokens)
{
	int		count;
	t_token	*temp;

	temp = tokens;
	count = 0;
	while (temp != NULL)
	{
		count++;
		temp = temp->next;
	}
	return (count);
}

int	count_token_argc(t_token *tokens, int num_command)
{
	t_token	*temp;
	int		argc;

	temp = tokens;
	while (temp != NULL && 0 < num_command - 1)
	{
		if (temp->type == PIPE)
			num_command--;
		temp = temp->next;
	}
	argc = 0;
	while (temp != NULL && temp->type == WORDS)
	{
		argc++;
		temp = temp->next;
	}
	return (argc);
}

/* count commands by count number of '|' */
int	count_commands(t_token *tokens)
{
	int		count;
	t_token	*temp;

	temp = tokens;
	count = 1;
	while (temp != NULL)
	{
		if (temp->type == PIPE)
			count++;
		temp = temp->next;
	}
	return (count);
}

char	**tokens_to_argv(t_token *tokens, int index_command)
{
	char	**argv;
	t_token	*temp;
	int		i;

	argv = malloc(sizeof(char *) * (count_token_argc(tokens, index_command) + 1));
	if (argv == NULL)
		exit_with_perror("malloc", NULL, NULL);
	temp = tokens;
	while (temp != NULL && 0 < index_command)
	{
		if (temp->type == PIPE)
			index_command--;
		temp = temp->next;
	}
	i = 0;
	while (temp != NULL && temp->type == WORDS)
	{
		argv[i] = ft_strdup(temp->value);
		if (argv[i] == NULL)
			exit_with_perror("malloc", NULL, NULL);
		temp = temp->next;
		i++;
	}
	argv[i] = NULL;
	return (argv);
}

int	is_last_command(t_token *tokens, int num_command)
{
	t_token	*temp;
	int		i;

	temp = tokens;
	i = 0;
	while (temp != NULL)
	{
		if (temp->type == PIPE)
			i++;
		if (i == num_command)
			break ;
		temp = temp->next;
	}
	if (temp->next == NULL)
		return (TRUE);
	return (FALSE);
}

int count_str_array(char **args)
{
	int i;

	i = 0;
	while (args[i] != NULL)
		i++;
	return (i);
}
