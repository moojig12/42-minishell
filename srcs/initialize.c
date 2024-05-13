/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandakh <nmandakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 14:44:06 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/05/13 16:38:55 by nmandakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**malloc_env(char **env)
{
	char	**dup_env;
	int		i;

	i = 0;
	while (env[i])
		i++;
	dup_env = (char **)malloc((i + 1) * sizeof(char *));
	i = 0;
	while (env[i])
	{
		dup_env[i] = ft_strdup(env[i]);
		i++;
	}
	dup_env[i] = 0;
	return (dup_env);
}

t_values	*init_values(char **env)
{
	t_values	*ptr;

	ptr = malloc(sizeof(t_values));
	if (!ptr)
		return (NULL);
	ptr->head_token = NULL;
	ptr->total_tokens = 0;
	ptr->env = malloc_env(env);
	ptr->syntax_error = 0;
	ptr->last_error_code = 0;
	return (ptr);
}

void reset_vals_elements(t_values *vals)
{
	if (vals->head_token != NULL)
		free_token(vals->head_token);
	vals->head_token = NULL;
	vals->total_commands = 0;
	vals->total_tokens = 0;
	vals->syntax_error = 0;
	// vals->last_error_code = 0;
	return ;
}
