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

void	free_int_array(int **array, int row)
{
	int	i;

	i = 0;
	while (i < row)
		free(array[i++]);
	free(array);
}
