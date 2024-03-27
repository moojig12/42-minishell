/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandakh <nmandakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 15:25:17 by marvin            #+#    #+#             */
/*   Updated: 2024/03/27 16:36:43 by nmandakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	*iswhitespace(char c)
{
	if (c == '\t' | c == '\n' | c == ' ')
		return (&c);
	else
		return (NULL);
}

/* int	count_words(char *input)
{
	int	words;
	int	i;

	i = 0;
	words = 0;
	skip_space(input, &i);
	while (input[i])
	{
		while (!iswhitespace(input[i]))
		{
			i++;
		}
		words++;
		skip_space(input, &i);
	}
	return (words);
} */