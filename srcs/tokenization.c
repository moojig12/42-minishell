/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandakh <nmandakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 15:13:58 by marvin            #+#    #+#             */
/*   Updated: 2024/03/27 17:33:21 by nmandakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/minishell.h"

void	init(t_token *new)
{
	new->type = INT_MIN;
	new->value = NULL;
	new->next = NULL;
	new->prev = NULL;
}

void	convert_to_token(t_token **tokens, char *input, int word)
{
	int	i;
	t_token	*new_token;

	new_token = malloc(sizeof(t_token));
	init(new_token);
	if (word == 1)
		new_token->type = 1;
	i = 0;
	new_token->value = (char *)malloc((count_letters(input) + 1) * sizeof(char));
	while (!iswhitespace(*input) && *input)
	{
		new_token->value[i] = *input;
		input++;
		i++;
	}
	new_token->value[i] = '\0';
	add_to_back(tokens, new_token);
}

int	lexical_analysis(t_token **tokens, char *input)
{
	int	word;
	int	i;

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
		if (input[i])
			skip_space(input, &i);
		word++;
	}
	return (word);
}
