/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandakh <nmandakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 15:13:58 by marvin            #+#    #+#             */
/*   Updated: 2024/03/27 16:36:47 by nmandakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	convert_to_token(t_token **tokens, char *input, int word)
{
	int	i;
	t_token	*new_token;

	add_to_back(tokens, new_token);
	if (word == 1)
		new_token->type = 1;
	i = 0;
	new_token->value = (char *)malloc((count_letters(input) + 1) * sizeof(char));
	while (!iswhitespace(*input))
	{
		new_token->value[i] = *input;
		input++;
		i++;
	}
}

int	lexical_analysis(t_token **tokens, char *input)
{
	int	word;
	int	i;
	int	j;

	/* word = count_words(input);
	if (word == 0)
		error("No arguments found"); */
	i = 0;
	word = 1;
	skip_space(input, &i);
	while (input[i])
	{
		convert_to_token(tokens, &input[i], word);
		skip_letters(input, &i);
		skip_space(input, &i);
		word++;
	}
	return (word);
}
