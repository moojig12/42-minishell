/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 14:44:06 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/04/16 19:49:52 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	**calloc_int_array(int row, int column)
{
	int	**array;
	int	count_row;

	array = (int **)malloc(sizeof(int *) * row);
	if (array == NULL)
		return (NULL);
	count_row = 0;
	while (count_row < row)
	{
		array[count_row] = (int *)ft_calloc(column, sizeof(int));
		if (array[count_row] == NULL)
		{
			free_int_array(array, count_row);
			return (NULL);
		}
		count_row++;
	}
	return (array);
}

void	free_int_array(int **array, int row)
{
	int	count_row;

	count_row = 0;
	while (count_row < row)
	{
		free(array[count_row]);
		count_row++;
	}
	free(array);
}
