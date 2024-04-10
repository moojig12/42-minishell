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

	// while loop adjusted to fix memory leak, needs testing

void	free_token(t_token *head)
{
	int		i;
	int		size;
	t_token	*temp;
	t_token	*next;

	if (head == NULL)
		return ;
	temp = head;
	i = 0;
	size = count_token(temp);
	while (i < size)
	{
		next = temp->next;
		free(temp->value);
		temp = next;
		i++;
	}
	free(temp);
	return ;
}

//TODO: free history?
