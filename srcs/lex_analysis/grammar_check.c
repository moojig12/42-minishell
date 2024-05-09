/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grammar_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 12:46:47 by root              #+#    #+#             */
/*   Updated: 2024/05/07 12:18:20 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	grammar_check(t_token *tokens, t_values *val)
{
	// If grammar error set syntax error to -1
	while (tokens)
	{
		if (is_operator(tokens->next->value))
			return 1;
		tokens = tokens->next;
	}
}