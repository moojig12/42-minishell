/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 15:13:58 by marvin            #+#    #+#             */
/*   Updated: 2024/03/29 12:21:54 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* int	count_words(char *input)
{
	int	words;
	int	i;

	i = 0;
	words = 0;
	skip_space(input, &i);
	while (input[i])
	{
		while (!is_whitespace(input[i]))
		{
			i++;
		}
		words++;
		skip_space(input, &i);
	}
	return (words);
} */

/*
void	convert_to_token(t_token **tokens, char *input, int word)
{
	int	i;
	t_token	*new_token;

	add_to_back(tokens, new_token);
	if (word == 1)
		new_token->type = 1;
	i = 0;
	new_token->value = (char *)malloc((count_letters(input) + 1) * sizeof(char));
	while (!is_white_space(*input))
	{
		new_token->value[i] = *input;
		input++;
		i++;
	}
}
*/

/*
int	lexical_analysis(t_token **tokens, char *input)
{
	int	word;
	int	i;
	int	j;

	// word = count_words(input);
	// if (word == 0)
	// 	error("No arguments found");
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
*/
