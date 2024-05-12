/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandakh <nmandakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 14:44:06 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/05/12 16:35:30 by nmandakh         ###   ########.fr       */
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
	array = NULL;
}

// while loop adjusted to fix memory leak, needs testing
void	free_token(t_token *head)
{
	t_token	*temp;
	t_token	*next;

	if (head == NULL)
		return ;
	temp = head;
	while (temp != NULL)
	{
		next = temp->next;
		free(temp->value);
		free(temp);
		temp = next;
	}
}

void	free_vals_elements(t_values *vals)
{
	free_token(vals->head_token);
	free_args(vals->env);
	free(vals);
	vals = NULL;
}
