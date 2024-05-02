/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 15:25:17 by marvin            #+#    #+#             */
/*   Updated: 2024/04/23 17:43:16 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*last_node(t_token *node)
{
	t_token	*temp;

	if (!node)
		return (NULL);
	temp = node;
	while (temp->next)
		temp = temp->next;
	return (temp);
}

void	add_to_back(t_token **tokens, t_token *new)
{
	t_token	*last;

	last = *tokens;
	if (!tokens | !(*tokens))
		*tokens = new;
	else
	{
		last = last_node(last);
		last->next = new;
		new->prev = last;
	}
}
