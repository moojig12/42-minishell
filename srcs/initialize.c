/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 14:44:06 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/04/16 19:49:52 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_values	*init_values(t_values *vals, char **env)
{
	if (vals)
	{
		free_vals(vals);
		return (NULL);
	}
	vals = malloc(sizeof(t_values));
	if (!vals)
		return (NULL);
	vals->head_token = NULL;
	vals->total_commands = 0;
	vals->total_tokens = 0;
	vals->env = env;
	vals->syntax_error = 0;
	vals->last_error_code = 0;
	return (vals);
}
