/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 14:44:06 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/05/06 22:18:53 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_values	*init_values(char **env)
{
	t_values	*ptr;

	ptr = malloc(sizeof(t_values));
	if (!ptr)
		return (NULL);
	ptr->head_token = NULL;
	ptr->total_tokens = 0;
	ptr->total_commands = 0;
	ptr->head_io = NULL;
	ptr->env = env;
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
