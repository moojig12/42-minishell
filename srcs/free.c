/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 14:44:06 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/04/16 19:49:52 by yjinnouc         ###   ########.fr       */
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
	// int		i;
	t_token	*temp;
	t_token	*next;

	if (head == NULL)
		return ;
	temp = head;
	// i = 0;
	while (temp != NULL)
	{
		next = temp->next;
		free(temp->value);
		temp = next;
		// i++;
	}
	free(temp);
	return ;
}

void free_args(char	**args)
{
	int	i;

	i = 0;
	while (args[i] != NULL)
		free(args[i++]);
	free(args);
}

int **calloc_int_array(int row, int column)
{
	int	**array;
	int	i;

	array = (int **)malloc(sizeof(int *) * row);
	if (array == NULL)
		return (NULL);
	i = 0;
	while (i < row)
	{
		array[i] = (int *)ft_calloc(column, sizeof(int));
		if (array[i] == NULL)
		{
			free_int_array(array, i);
			return (NULL);
		}
		i++;
	}
	return (array);
}

void free_int_array(int **array, int row)
{
	int	i;

	i = 0;
	while (i < row)
		free(array[i++]);
	free(array);
}
