/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 15:13:58 by marvin            #+#    #+#             */
/*   Updated: 2024/03/25 15:13:58 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	lexical_analysis(t_token **tokens, char *input)
{
	char **arguments;
	int	i;
	int	words;

	if (!input)
		return (-1);
	i = 0;
	words = 0;
	//	Count the number of words
	while (input[i])
	{
		if (iswhitespace(input[i]))
		{
			while (iswhitespace(input[i]) && input[i])
			{
				i++;
			}
			if (input[i] != ';' && input[i])
				words++;
		}
		i++;
	}
	//	Loop over string and seperate words into char **arguments
	arguments = (char **)malloc(words * sizeof(char *));
	return ;
}