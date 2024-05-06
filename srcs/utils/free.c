/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 14:44:06 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/05/04 10:59:53 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_array_err(char **argv)
{
	int	i;

	i = 1;
	while (argv[i] != NULL)
		free(argv[i++]);
	free(argv);
	argv = NULL;
}

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
	free(vals);
	vals = NULL;
}
