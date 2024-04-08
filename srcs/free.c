/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 14:44:06 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/04/08 19:01:20 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i] != NULL)
		free(array[i++]);
	free(array);
}

void	free_token(t_token *head)
{
	int		i;
	t_token	*temp;
	t_token	*next;

	if (head == NULL)
		return ;
	temp = head;
	i = 0;
	while (temp != NULL)
	{
		next = temp->next;
		free(temp->value);
		free(temp);
		temp = next;
	}
	return ;
}

//TODO: free history?
