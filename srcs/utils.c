/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandakh <nmandakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 15:25:17 by marvin            #+#    #+#             */
/*   Updated: 2024/04/03 18:39:15 by nmandakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/minishell.h"

// TODO: fix compile error

void	*is_whitespace(char c)
{
	if (c == '\t' | c == '\n' | c == ' ')
		return (1);
	else
		return (0);
}

t_token	*last_node(t_token *node)
{
	t_token	*temp;

	if (!node)
		return (NULL);
	temp = node;
	while(temp->next)
	{
		temp = temp->next;
	}
	return (temp);
}

