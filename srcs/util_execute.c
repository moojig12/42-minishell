/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 18:08:23 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/04/23 18:14:24 by yjinnouc         ###   ########.fr       */
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
	int		count;
	t_token	*temp;
	int		count_command;

	count_command = 0;
	temp = tokens;
	while (temp != NULL && num_command < count_command)
	{
		if (temp->type == 2)
			count++;
		temp = temp->next;
	}
	count = 0;
	while (temp != NULL && temp->type < 2)
	{
		count++;
		temp = temp->next;
	}
	return (count);
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
		if (temp->type == 2)
			count++;
		temp = temp->next;
	}
	return (count);
}

char	**tokens_to_argv(t_token *tokens, int num_command)
{
	char	**argv;
	t_token *temp;
	int		i;

	argv = malloc(sizeof(char *) * (count_token_argc(tokens, num_command) + 1));
	if (argv == NULL)
		exit_with_perror("malloc", NULL, NULL);
	temp = tokens;
	while (temp != NULL && 0 < num_command)
	{
		if (temp->type == 2)
			num_command--;
		temp = temp->next;
	}
	i = 0;
	while (temp != NULL && temp->type < 2)
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

int is_last_command(t_token *tokens, int num_command)
{
	t_token *temp;
	int		i;

	temp = tokens;
	i = 0;
	while (temp != NULL)
	{
		if (temp->type == 2)
			i++;
		if (i == num_command)
			break;
		temp = temp->next;
	}
	if (temp->next == NULL)
		return (TRUE);
	return (FALSE);
}
